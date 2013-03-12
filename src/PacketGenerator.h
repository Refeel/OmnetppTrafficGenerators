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

#ifndef PACKETGENERATOR_H_
#define PACKETGENERATOR_H_

#include <SimplePacket_m.h>
#include <PacketPriority.h>

namespace omnetpptrafficgenerators {

class PacketGenerator {
public:
    PacketGenerator();
    PacketGenerator(int delayBeetweenPackets, int packetsLength, int sessionLength, PacketPriority packetsPriority);
    virtual ~PacketGenerator();

    virtual SimplePacket generatePacket();  // to override

    void setDelayBeetweenPackets(int delay);
    void setPacketsLength(int len);
    void setSessionLength(int len);
    void setPacketsPriority(PacketPriority priority);

    int getDelayBeetweenPackets();
    int getPacketsLength();
    int getSessionLength();
    int getPacketsPriority();

private:
    //PARAMS:
    int _delayBeetweenPackets;
    int _packetsLength;
    int _sessionLength;
    PacketPriority _packetsPriority;

};

} /* namespace omnetpptrafficgenerators */
#endif /* PACKETGENERATOR_H_ */
