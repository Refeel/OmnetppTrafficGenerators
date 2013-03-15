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

#include "PoissonPacketGenerator.h"

namespace omnetpptrafficgenerators {

PoissonPacketGenerator::PoissonPacketGenerator() {
    // TODO Auto-generated constructor stub

}

PoissonPacketGenerator::~PoissonPacketGenerator() {
    // TODO Auto-generated destructor stub
}

SimplePacket *PoissonPacketGenerator::generatePacket() {
    return new SimplePacket("generatedPacket");
}

void PoissonPacketGenerator::initialize() {
    setPacketsNumber(100);  //TODO: get from params

    this->_packetsCount = 0;
    this->generatedPacket = new SimplePacket("selfMessage");
    scheduleAt(simTime() + 1, this->generatedPacket);
}

void PoissonPacketGenerator::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) { // received self message
        if (this->_packetsCount < this->_packetsNumber) {
            this->generatedPacket = generatePacket();

            int delay = poisson(5);//par("poissonDelayTime"); cos nie dziala pobieranie losowych z parametrow tak jak powinno

            scheduleAt(simTime() + delay, this->generatedPacket);  // send genrated message: scheduleAt() OR send()

            this->generatedPacket = NULL; // remove after send

            std::string buf;
            sprintf((char*)buf.c_str(), "Message number %d generated with delay %d", this->_packetsCount++, delay);

            EV << *buf.c_str();
            bubble(buf.c_str());
        }

    } else { // received true packet
        // processing received packet....
        SimplePacket *sPacket = check_and_cast<SimplePacket *>(msg);  // dynamic cast
        sPacket = NULL;

    }
}

void PoissonPacketGenerator::finish() {
    if (this->generatedPacket != NULL)
        delete this->generatedPacket;
}

} /* namespace omnetpptrafficgenerators */
