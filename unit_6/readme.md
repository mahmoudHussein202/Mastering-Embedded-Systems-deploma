# What's meant by : 
-------------------
# Micro-processor:
*   Micro-processor is an ic which can do arithmatic and logical operations.
# Micro- Controller:
* is a Micro-processor with a bus and some other peripherals
# Embedded Systems :
* a special purpose computer, it's designed to perform certain tasks efficiently
# Mechatronic system :
* the integration of mechanical systems and the Embedded Systems
# n-bit processor : 
* a processor that can process 8-bits at the same clock cycle, so all the registers are 8 bits, so the data bus also is 8 bit.
-----------------------------------------------
# Answer those questions : 
--------------------------
* Comparte between micro-processor and micro-controller :

    -   the micro-processor is an  ic that can do arithmatic and logical operations, it consists of ALU 
        for calculations, control unit for controlling the sequences of the operations and understaning the op-codes, and registers which divided into general purpose registers and special purpose registers.
    -   micro-controller is simply a micro-processor, a bus and peripherals that responsible for some
        tasks, there is a more powerful micro-controller which called (SOC) or system on chip, this is more powerful and have more capabilities like it may have modules for graphics processing and audio processing.

* Compare between von-neuman and harvard;

    -   Von-neumann : it's the architecture where one bus is used for data and instructions, also
        one memory is used, likely the memory is divided, so part for data and part for instruction.
        you can't fetch an instruction and store a data at the same time, the bus must be available to do one thing, so pipelining can't be used in this architecture
    -   Harvard : it's the architecture used in embedded systems, there are two seprate busses for
        data and instructions, also there's two seprate memories for data and instructions, this architechture is faster than von neumann but it needs a lot of resources and size to make it on a bigger scale like PCs,

*   illustrate the type of ROMS
    -   ROM: read only memory
    -   EROM: Erasable read only memory, can be erased completly using UV rays, i can't Erase
                a particular byte
    -   EEPROM: Electrically Erased ROM, i can erase it's content electrically.
    -   flash memory: the better form of EEPROM which is lager and faster.
    -   all of the are non-volatile memories

* illustrate the types of RAMS:
    -   SRAM : static random access memory, it's very fast but also very expensive and small storage
                size, that's because the bit holder is a flipFlop. composed of 6 transistors, but the best part of it is it doesn't need to be refreshed, you assign the data once in it
    -   DRAM :  Dynamic random access memory, it's relativley fast if compared with Flash memories,
                but it's slower than the sRam, and we can't make it connected direct to the cpu because a huge bottleneck will happened, DRAM considerd very slow compared to the SRAM and the CPU because it needs to be refreshed every 64ms, so we can't access anything in the DRAM while refreshing, but the best advantage in it is the size of the bit holder which is very small, because it composed of one transistor and one capacitor only, this allow us to make large DRAMS if compared to SRAMS
    -   Both are volatile memories
    -   NV-RAM(non-volatile RAM):it's an SRAM but have a backup battery with it as a source of energy
                                 if the power is cut off, so it can retain it's content up to 10 years after the power is switched off, another types of NV-RAMS store the content in the flash memory after power is switched-off,

* Why ROM is read only memory although i can write on it ?
    -   ROMs are read only memory that can used in storing some important codes and configuartions like
        the bios for example, but we can write on it because there are some types of ROMs allow us to write on it such as EROM and EEPROM.
        but it's very important to know that the CPU in normal conditions have to access to the ROM, so if the CPU needs to write on the ROM, it need a special configuration to access or by using an external device, so it's called Read only memories.


