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

import omnetpptrafficgenerators.PoissonPacketGenerator;

simple PoissonPacketGenerator
{
    parameters:
        int poissonDelayTime;
    gates:
        input in;
        output out;
}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network TestNetworkPoisson
{
    submodules:
        tic: PoissonPacketGenerator;
        toc: PoissonPacketGenerator;
    connections:
        tic.out --> {delay = 100ms;} --> toc.in;
        tic.in <-- {delay = 100ms;} <-- toc.out;


}

