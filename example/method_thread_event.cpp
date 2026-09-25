#include <systemc>
using namespace sc_core;

// Module of an AndGate using Method
SC_MODULE(AndGate) {
    sc_in<bool> a{"a"};
    sc_in<bool> b{"b"};
    sc_out<bool> y{"y"};

    void comb() {
        y.write(a.read() && b.read());
    }

    SC_CTOR(AndGate) {
        SC_METHOD(comb);
        sensitive << a << b ;
    }
};

// Module of a Timer using Thread
SC_MODULE(Timer) {
    sc_event done ;

    // The Timer wait for 100ns and send a done event when it is done
    void run() {
        wait(100, SC_NS);
        done.notify();
        std::cout << "Timer done at " << sc_time_stamp() << std::endl ;
    }

    SC_CTOR(Timer) {
        SC_THREAD(run);
    }
};

// Consumer that wait for the done event 
SC_MODULE(Consumer) {
    sc_event producer_done;

    void consumer_thread() {
        while (true) {
            wait(producer_done);
            consume_result() ;
        }
    }

    void consume_result() {
        std::cout<< "Result consumed at " << sc_time_stamp() << std::endl;
    }

    SC_CTOR(Consumer) {
        SC_THREAD(consumer_thread);
    }
};

int sc_main(int, char*[]) {
    // And Gate
    sc_signal<bool> sig_a, sig_b, sig_y;
    AndGate and_gate("and_gate");
    and_gate.a(sig_a);
    and_gate.b(sig_b);
    and_gate.y(sig_y);

    // Timer Example
    Timer timer{"timer"};

    // Consumer Example
    Consumer cons{"cons"};
    cons.producer_done.notify(10, SC_NS);

    sc_start(200, SC_NS);
    return 0;
}