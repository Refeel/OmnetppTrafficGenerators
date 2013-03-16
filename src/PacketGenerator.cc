//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "PacketGenerator.h"
#include <PacketPriority.h>
#include <cstdio>

namespace omnetpptrafficgenerators {


PacketGenerator::PacketGenerator() {
    // TODO Auto-generated constructor stub

}

PacketGenerator::PacketGenerator(int packetsNumber, int delayBeetweenPackets, int packetsLength, int sessionLength, PacketPriority packetsPriority) {
    this->_packetsNumber = packetsNumber;
    this->_delayBeetweenPackets = delayBeetweenPackets;
    this->_packetsLength = packetsLength;
    this->_sessionLength = sessionLength;
    this->_packetsPriority = packetsPriority;
}

PacketGenerator::~PacketGenerator() {
    // TODO Auto-generated destructor stub
}

} /* namespace omnetpptrafficgenerators */

void PacketGenerator::setPacketsNumber(int packetsNum) {
    this->_packetsNumber = packetsNum;
}

void PacketGenerator::setDelayBeetweenPackets(int delay) {
    this->_delayBeetweenPackets = delay;
}

void PacketGenerator::setPacketsLength(int len) {
    this->_packetsLength = len;
}

void PacketGenerator::setSessionLength(int len) {
    this->_sessionLength = len;
}

void PacketGenerator::setPacketsPriority(PacketPriority priority) {
    this->_packetsPriority = priority;
}

int PacketGenerator::getPacketsNumber() {
    return this->_packetsNumber;
}

int PacketGenerator::getDelayBeetweenPackets() {
    return this->_delayBeetweenPackets;
}

int PacketGenerator::getPacketsLength() {
    return this->_packetsLength;
}

int PacketGenerator::getSessionLength() {
    return this->_sessionLength;
}

int PacketGenerator::getPacketsPriority() {
    return this->_packetsPriority;
}

simtime_t PacketGenerator::getDelay() {
    return 10;
}

SimplePacket *PacketGenerator::generatePacket() {

    int src = getIndex();
    int n = size();
    int dest = intuniform(0,n-2);
    if (dest>=src) dest++;

    char msgname[20];
    sprintf(msgname, "tic-%d-to-%d", src, dest);

    SimplePacket *sp = new SimplePacket(msgname);

    sp->setDST(dest);
    sp->setSRC(src);
    sp->setSessionId(0);
    sp->setPacketId(this->_packetsCount++);
    sp->setPriority(NORMAL);

    return sp;
}

void PacketGenerator::forwardPacket(SimplePacket *sp) {

    // Same routing as before: random gate.
    int n = gateSize("gate");
    int k = intuniform(0,n-1);

    EV << "Forwarding packet " << sp << " on gate[" << k << "]\n";
    send(sp, "gate$o", k);
}

void PacketGenerator::initialize() {

    this->event = new cMessage("event");
    this->generatedPacket = NULL;

    setPacketsNumber((int)par("packetsNumber"));

    this->_packetsCount = 0;

    scheduleAt(simTime() + 1, event);
}

void PacketGenerator::handleMessage(cMessage *msg) {
    if (msg == event) { // received timing message
        if (this->_packetsCount < this->_packetsNumber) {
            this->generatedPacket = generatePacket(); // generate periodic packet

            forwardPacket(this->generatedPacket); // send to random node

            this->generatedPacket = NULL; // remove after send


            simtime_t delay = getDelay();
            scheduleAt(simTime() + delay, event);

            std::string buf;
            sprintf((char*) buf.c_str(), "Packet number %d generated with delay %lf", this->_packetsCount, delay.dbl());
            EV << buf.c_str();
            bubble(buf.c_str());

        }

    } else { // received true packet
        // processing received packet....
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg); // dynamic cast

        if (sPacket->getDST() == getIndex()) {
            EV << "Packet " << sPacket << " arrived\n";

            delete sPacket;
        } else {
            forwardPacket(sPacket);
        }

    }
}

void PacketGenerator::finish() {
    if (this->generatedPacket != NULL)
        delete this->generatedPacket;
}
