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
cmake -DCMAKE_INSTALL_PREFIX=/your/custom/path ..
cmake ../systemc-3.0.2 -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=/Users/henryfan/SystemC

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

The Core Mental Model
A SystemC executable has two lives. First, normal C++ constructs objects. Then the SystemC kernel elaborates those objects into a simulation hierarchy and runs registered processes.

sc_start() hands control to the scheduler. From that point on, time, events, and process readiness decide what runs.

Maps of the course
C++ setup and the shape of a SystemC program
Modules, hierarchy, constructors, and elaboration
Processes, sensitivity, events, waits, and delta cycles
Ports, interfaces, exports, channels, and binding
Signals, resolved signals, clocks, and writer policies
TLM-2.0 payloads, sockets, timing, and protocol phases
Source-code reading: scheduler, signals, ports, exports, sockets, and process control
Practical patterns for virtual platforms and deployable documentation

# Build SystemC and Write a First Model
Use Docs/LRMs/SystemC_LRM_1666-2023.pdf to check what the kernel promises during elaboration and simulation startup.

Construction: C++ constructors allocate modules, channels, and local state.
Elaboration: SystemC finalizes hierarchy, port bindings, process registration, and object names.
Simulation: sc_start() lets the kernel run processes according to events and time.

Keep the first model small. Build one clock, one signal, one module, and one print statement.
I need to change it in order to fix the 
multiple errors: tapi error: malformed file
error: unknown architecture
The issue is because my Xcode command line tool is out of sync with the MacOS
```
sudo xcode-select -switch /Library/Developer/CommandLineTools
```

Also, need to force the use of standard C++17.
Need to add a fake signature for the dynamically link path used.
```
g++ -std=c++17 main.cpp -o hello_systemc  -I/Users/henryfan/SystemC/include -L/Users/henryfan/SystemC/lib -lsystemc -lm
install_name_tool -add_rpath /Users/henryfan/SystemC/lib hello_systemc 
```

# Modules, Hierarchy, and Elaboration

SC_MODULE is a convenience macro around a C++ class derived from sc_module.
You can also write explicit C++ classes derived from sc_module, which is useful when templates or inheritance become more important than brevity.

Producer producer{"producer"};  "Module name, instance name, instance name"

Elaboration Is the Build Step Inside the Executable

Construct child modules before binding them. This style keeps topology in the parent constructor, where readers expect to find it.

The big idea: SystemC uses ordinary C++ construction, but overlays a hierarchy-tracking discipline on top of it.

# Processs, Events, and Time
 Modules provide structure. Channels provide communication. Processes provide activity.

SC_METHOD: runs to completion and cannot call wait().
SC_THREAD: can suspend with wait() and resume later.

Use SC_METHOD for combinational behavior or small reactions to events: (has sensitive list)

Use SC_THREAD when behavior has an internal timeline:

An sc_event is not a queue of messages. It is a notification mechanism. 


A delta cycle is a zero-time scheduling step. It lets the kernel settle chains of events without advancing simulation time.

Signal writes use this idea: a process writes a new value, the channel schedules an update, and dependent processes wake in a later delta cycle (zero-time scheduling steps).

Most SystemC timing surprises become ordinary once you separate time advancement from delta-cycle settling.

sc_thread_process: Requires its own execution stack to support wait(). Under the hood, the Accellera kernel uses a coroutine library. On Linux/Windows, it typically uses QuickThreads (src/sysc/qt/) or POSIX fibers. When wait() is called,  he coroutine context is saved, and execution yields back to the SystemC scheduler. When an sc_event::notify() is called, the kernel pushes the event into sc_simcontext::m_event_list. At the end of the delta cycle, the scheduler wakes up all processes statically or dynamically sensitive to that event by moving them into the m_runnable list.

# Datatypes and Bit-Accurate Modeling

 can a normal C++ type answer this modeling question? If yes, use it. If the model needs hardware-shaped behavior, use SystemC datatypes.


https://www.accellera.org/downloads/standards/systemc

# Too Early to tell
using namespace
kernel behavior
macro and type
Smart Pointers - scv_smart_ptr
Configuration, Control and Inspection (CGI)
SystemC verification library
UVM-SystemC
ESL architect
channel
dont_initialize
Why a module has 2 instance names
If nobody is waiting when an immediate event is notified, the event is missed.

