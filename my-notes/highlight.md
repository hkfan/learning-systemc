# C++ Prerequisites

reference
SystemC_LRM_1666-2023.pdf - exact mathematical or logical rules governing the simulator
Accellera SystemC GitHub repository for kernel behavior
Accellera SystemC GitHub repository for bit-accurate C++ types

SystemC is a OOP
	sc_module is a class
	SC_CTOR is a constructor
	inhertance
	polymorphism and virtual function

Pass-by-reference & - large payload
Pointer - dynamaically allocated modules
Smart Pointer - 
Port, signals and FIFOs are templated classes. 
operator << for sensivity lists and port binding (not bit shifting)
operator = for reading/writing signals
Standard Template Library std::vector, std::string, std::cout, std::endl

Leveraging advanced C++ paradigms to mimic hardware concurrency.

# Installation And Setup

SystemC is a library and it is not an executable

The repo is in here
https://github.com/accellera-official/systemc

Use CMAKE_INSTALL_PREFIX to specify the path to install

You must tell the compiler where the SystemC headers (-I) and library files (-L) are located, and explicitly link the systemc library (-lsystemc).

The 'I,L' is the path and the 'l' is the name of the library

The idea of the installation and setup is to download the source code of SystemC, compile it locally, and install it in a location so that when the SystemC library is called, the local compiler can reference that.

The source code can be downloaded from the Accellera GitHub server. <- Compile it
When compiling the library, there are 2 steps:
creating the build folder
specify the installation location
execute the compile command

# Official Resources Hub
SystemC is an open standard maintained by the Accellera Systems Initiative and standardized by the IEEE.
Accellera Community Forums
- Accellera SystemC Community Forum - https://forums.accellera.org/forum/9-systemc/
- TLM Discussion Forum - https://forums.accellera.org/forum/12-tlm/
- SystemC AMS Discusion Forum - https://forums.accellera.org/forum/13-systemc-ams/

Official Source Code Repositories
- SystemC Core: github.com/accellera-official/systemc
- Configuration, Control & Inspection (CCI): github.com/accellera-official/cci
- SystemC Verification Library (SCV): github.com/accellera-official/scv
- UVM-SystemC: github.com/accellera-official/uvm-systemc

# Introduction to SystemC
SystemC is a C++ class library and simulation kernel for modeling systems whose behavior is naturally concurrent: processors, buses, accelerators, interconnects, memories, peripherals, firmware-visible registers, and virtual platforms.

is a 
- C++ class library
- simulation kernel

functions
- modeling system whose behaviour is concurrent
- elaborate
- schedule
- simulate

examples
- processors
- buses
- accelerators
- interconnects
- memories
- peripherals
- registers
- virtual plaform

Objects
- modules
- ports
- signals
- events
- time
- processes
- transaction level modeling

sc_module - a place in hierarchy
sc_object - name and identity
sc_module_name - helps construction work cleanly
sc_simcontext - kernel object that eventually runs the simulation



# Too Early to tell
kernel behavior
macro and type
Smart Pointers - scv_smart_ptr
Configuration, Control and Inspection (CGI)
SystemC verification library
UVM-SystemC
ESL architect



