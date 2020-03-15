# verbose-carcrash
This is an experimental ARM OS, under no circumstance should it be ran on anything and I am not at all responsible for bricking your crap. It is actually called verbose"carcrash" so I feel like I don't have to say that. The goals of this is for me to grasp the difficulty because honestly as I'm writing this I'm wondering what is so hard about writing a OS totally around ARM that is totally designed around IoT and the goals of IoT.

Massive thanks to @jserv and his mini-arm-os which I also stole to start with.

# Building

Make has a few commands atm.

**make version** - Print the newest possible version of the OS

**make clean** - Delete the releases folder

# Structure

**/platform/**

Platform specific functions for things like startup, serial, etc.

**/core/**

Core of the operating system that is common across all instances, sort of is the OS.

**/cmsis/**

Generic APIs for things like SPI, register locations, etc.

# Goals

* Multi-threading of services on timers, with priorities, and with hardware IRQs.
* Remove the concept of "userspace", it is now servicespace, there are no users here. Possibly make processes require signing?
* Demonstrate a working abstraction between multiple ARM processors.
* Have some loose concept of drivers that is dump and naive
* Implement a filesystem _maybe_ that works on flash ICs and SD cards.

The final goal that will not be accomplished in this project is to create a OS that can dynamically load binaries then run them as processes.
