#include <iostream>
#include <cstdint>
#include <functional>
#include <boost/circular_buffer.hpp>


enum class state : size_t {
    CHECK = 1<<0,
    FLUSH = 1<<1,
    RECOV = 1<<2,
};


struct sample {
    std::int64_t t1;
    std::int64_t t2;
    std::uint16_t ts2r;
    sample (std::int64_t _t1, std::int64_t _t2, std::uint16_t _t) : t1{_t1}, t2{_t2}, ts2r{_t} {}
};

// This defines the flow of the FSM. In a different function the actions based
// on the state and transitions of the FSM can be used to act
state mly_fsm(const state& s, const boost::circular_buffer<sample>& samples) {
    state next;
    switch(s) {
        case state::FLUSH:
            std::cerr << "FLUSH\n";
            next = state::RECOV;
            break;
        case state::RECOV:
            std::cerr << "RECOV\n";
            next = state::CHECK;
            break;
        case state::CHECK:
        default:
            std::cerr << "CHECK\n";
            next = state::FLUSH;
            break;
    }
    return next;

}


int main() {
    state s{state::CHECK};
    boost::circular_buffer<sample> data;
    while (1) {
        s = mly_fsm(s, data);
    }
    return 0;
}
