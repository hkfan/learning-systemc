#include <systemc>
using namespace sc_core;

// Produce Module
SC_MODULE(Producer) {
    sc_out<int> out{"out"};

    void run() {
        // Write a number 0 to 3, each in 10ns
        for (int i = 0 ; i !=4 ; i++) {
            out.write(i) ;
            wait(10, SC_NS);
        }
    }

    SC_CTOR(Producer) {
        SC_THREAD(run);
    }
};

// Consumer Module
SC_MODULE(Consumer) {
    sc_in<int> in{"in"};

    // Run when in is changed.
    void process() {
        std::cout << "Consumer received: " << in.read()
        << " at " << sc_time_stamp() << std::endl;
    }

    SC_CTOR(Consumer) {
        SC_METHOD(process);
        sensitive << in ;
        dont_initialize() ;
    }
};

// Top Module 
SC_MODULE(Top) {
    sc_signal<int> data{"data"};
    Producer producer{"producer"};
    Consumer consumer{"consumer"};

    SC_CTOR(Top) {
        producer.out(data);
        consumer.in(data);
    }
};

// Run for 100ns
int sc_main(int, char*[]) {
    Top top{"top"} ;
    sc_start(100, SC_NS) ;
    return 0 ;
}
