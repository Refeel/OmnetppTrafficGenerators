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

#ifndef MARKOVPACKETGENERATOR_H_
#define MARKOVPACKETGENERATOR_H_

#include <PacketGenerator.h>
#include <SimplePacket_m.h>
#include <omnetpp.h>

namespace omnetpptrafficgenerators {

class MarkovPacketGenerator : public PacketGenerator{
public:

    MarkovPacketGenerator();
        virtual ~MarkovPacketGenerator();

        virtual SimplePacket *generatePacket(); // overrided
        virtual simtime_t getDelay();   // overrided

    protected:
        virtual void handleMessage(cMessage *msg);
        simtime_t _stateEndTime;// overrided

    private:
        void updateState();

        int _lambda;


    };



    Define_Module(MarkovPacketGenerator);

}


#endif /* MARKOVPACKETGENERATOR_H_ */
