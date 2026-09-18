#include <systemc>
using namespace sc_core;

SC_MODULE(Hello) {
    // The Exampe put say_hello at the bottom
    // I put it in the top to avoid too early reference
    void say_hello() {
        std::cout << "hello at " << sc_time_stamp() << "\n";
    }

    SC_CTOR(Hello) {
        SC_METHOD(say_hello);
    }
};

int sc_main(int, char*[]) {
    Hello top{"top"};
    sc_start() ;
    return 0 ;
}