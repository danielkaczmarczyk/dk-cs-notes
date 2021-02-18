# Chapter 1: Introduction

### Storage definitions and notation

| Unit | Size | Description |
| --- | --- | --- |
| bit | itself | Can hold only 0 or 1 |
| byte | 8 bits | Smallest convenient chunk of storage |
| word | depends | Given computer architecture's unit of storing data. A computer with 64-bit registers and 64-bit memory addressing typically will have a 64-bit (8 byte) words. |
| kilobyte KB | 1024 bytes | - |
| megabyte MB | 1024 ^ 2 bytes | - |
| gigabyte GB | 1024 ^ 3 bytes | - |
| terabyte TB | 1024 ^ 4 bytes | - |
| petabyte PB | 1024 ^ 5 bytes | - |


### Storage structure

- RAM, implemented commonly using semiconductor technology called DRAM, volatile
- EEPROM, electronically ereasable programmable read-only memory, to hold the _bootstrap program_ and other parts of _firmware_
- HDD, secondary storage - nonvolatile memory devices (NVM) 

### Definitions of coputer system components

- CPU - the hardware that executes instructions
- Processor - a physical chip that contains one or more CPUs
- Core - the basic computation unit of the CPU
- Multicore - including multiple computing cores on the same CPU
- Multiprocessor - including multiple processors
