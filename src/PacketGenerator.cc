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

SimplePacket *PacketGenerator::generatePacket() {
    return new SimplePacket("generatedPacket");
}

void PacketGenerator::initialize() {
    setPacketsNumber(100);  //TODO: get from params

    this->_packetsCount = 0;
    this->generatedPacket = new SimplePacket("selfMessage");
    scheduleAt(simTime() + 1, this->generatedPacket);
}

void PacketGenerator::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) { // received self message
        if (this->_packetsCount < this->_packetsNumber) {
            this->generatedPacket = generatePacket();

            scheduleAt(simTime() + 10.0, this->generatedPacket);  // send genrated message: scheduleAt() OR send()

            this->generatedPacket = NULL; // remove after send

            std::string buf;
            sprintf((char*)buf.c_str(), "Message number %d generated", this->_packetsCount++);

            EV << buf.c_str();
            bubble(buf.c_str());
        }

    } else { // received true packet
        // processing received packet....
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg);  // dynamic cast
        sPacket = NULL;

    }
}

void PacketGenerator::finish() {
    if (this->generatedPacket != NULL)
        delete this->generatedPacket;
}
