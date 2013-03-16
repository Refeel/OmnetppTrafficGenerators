//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2008 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

package omnetpptrafficgenerators.simulations;

import omnetpptrafficgenerators.OnOffPacketGenerator;

simple OnOffPacketGenerator
{
    parameters:
        int onOffDelayTime;
        int onOffStateDurationTime;
        int packetsNumber;
    gates:
        inout gate[];
}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network TestNetworkOnOff
{
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
        
    submodules:
        tic[6]: OnOffPacketGenerator;
    connections:
        tic[0].gate++ <--> Channel <--> tic[1].gate++;
        tic[1].gate++ <--> Channel <--> tic[2].gate++;
        tic[1].gate++ <--> Channel <--> tic[4].gate++;
        tic[3].gate++ <--> Channel <--> tic[4].gate++;
        tic[4].gate++ <--> Channel <--> tic[5].gate++;


}

