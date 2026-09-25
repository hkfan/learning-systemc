#include <systemc>
using namespace sc_core;

int sc_main(int argc, char* argv[]) {
    // Define signals and clocks
    sc_signal<bool> clk("clk");
    sc_signal<bool> reset("reset");
    sc_signal<uint> data_out("data_out");

    // --- 1. Create VCD trace file ---
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform_output");
    
    // (Optional) Set resolution to picoseconds (10^-12)
    tf->set_time_unit(1, SC_PS); 

    // --- 2. Register signals to be tracked ---
    sc_trace(tf, clk, "clock");
    sc_trace(tf, reset, "reset");
    sc_trace(tf, data_out, "data_out");

    // Initialize and run simulation
    reset.write(1);
    sc_start(10, SC_NS);
    
    reset.write(0);
    sc_start(40, SC_NS);

    // --- 3. Close the trace file ---
    sc_close_vcd_trace_file(tf);
    return 0;
}