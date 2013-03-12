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

namespace omnetpptrafficgenerators {

PacketGenerator::PacketGenerator() {
    // TODO Auto-generated constructor stub

}

PacketGenerator::PacketGenerator(int delayBeetweenPackets, int packetsLength, int sessionLength, PacketPriority packetsPriority) {
    this->_delayBeetweenPackets = delayBeetweenPackets;
    this->_packetsLength = packetsLength;
    this->_sessionLength = sessionLength;
    this->_packetsPriority = packetsPriority;
}

PacketGenerator::~PacketGenerator() {
    // TODO Auto-generated destructor stub
}

} /* namespace omnetpptrafficgenerators */

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

SimplePacket PacketGenerator::generatePacket() {
    return NULL;
}
