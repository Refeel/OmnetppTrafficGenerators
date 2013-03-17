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

#include "MarkovPacketGenerator.h"

namespace omnetpptrafficgenerators {

MarkovPacketGenerator::MarkovPacketGenerator() {
    //this->_stateEndTime = simTime()+par("markovStateDurationTime");
}

MarkovPacketGenerator::~MarkovPacketGenerator() {
    // TODO Auto-generated destructor stub
}

simtime_t MarkovPacketGenerator::getDelay() {
    simtime_t time = poisson(_lambda);
    return time;
}

SimplePacket *MarkovPacketGenerator::generatePacket() {

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

void MarkovPacketGenerator::handleMessage(cMessage *msg) {
    this->updateState();
    if (msg == event) { // received timing message
        if (this->_packetsCount < this->_packetsNumber) {

            simtime_t delay = getDelay();

            this->generatedPacket = generatePacket(); // generate periodic packet
            forwardPacket(this->generatedPacket); // send to random node
            hist.collect(delay.dbl());
            //vec.record(delay.dbl() + sumDelay.dbl());
            scheduleAt(simTime() + delay, event);

            this->generatedPacket = NULL; // remove after send

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

void MarkovPacketGenerator::updateState() {
    std::string buf;
    if(simTime() >= _stateEndTime) {
        this->_stateEndTime = simTime()+ intuniform(500,1500); //par("markovStateDurationTime");
        sprintf((char*) buf.c_str(), "State changed, endTime = %lf \n", this->_stateEndTime.dbl());
        _lambda = (rand()%((int)par("statesNum"))+1) * ((int)par("spaceBeetweenStates"));
        EV << buf.c_str();
        bubble(buf.c_str());
    }
}

} /* namespace omnetpptrafficgenerators */
