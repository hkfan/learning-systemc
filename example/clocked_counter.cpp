#include <systemc>
using namespace sc_core;

SC_MODULE(Counter) {
    sc_in<bool> clk{"clk"} ;
    sc_out<unsigned> value{"value"} ;
    unsigned internal = 0 ;

    void tick() {
        value.write(++internal);
        // Added the following to print the internal value
        std::cout << "The internal value of the counter is " << internal << std::endl ;
    }

    SC_CTOR(Counter) {
        SC_METHOD(tick);
        sensitive << clk.pos();
        dont_initialize();
    }
};

int sc_main(int, char*[]) {
    sc_clock clk{"clk", 10, SC_NS};
    sc_signal<unsigned> count{"count"};

    Counter counter{"counter"};
    counter.clk(clk);
    counter.value(count);

    sc_trace_file* tf = sc_create_vcd_trace_file("clocked_counter") ;
    tf->set_time_unit(1, SC_PS); 
    sc_trace(tf, clk, "clk");
    sc_trace(tf, count, "clock");
    sc_start(50, SC_NS);
    sc_close_vcd_trace_file(tf);
    return 0;
}