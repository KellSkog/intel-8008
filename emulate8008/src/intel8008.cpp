#include "intel8008.hpp"

    namespace detail {
    REGISTER A, B, C, D, E; // A is Acc
    uint16_t programcounter = 0;
    uint8_t stackIndex = 0;
    STACK Stack;
    Status status;
    Adr adr;
    std::function<void(uint8_t op)> LAA = []([[maybe_unused]]uint8_t op){A = A; ++programcounter;}; // 192

    Decode inst{nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,// 0*8*8=0,,7
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // (1*8-1)*8=56,,63

                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 1*8*8=64,,71
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // (2*8-1)*8=120,,127

                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 2*8*8=128,,135
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // (3*8-1)*8=184,,191

                detail::LAA,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 3*8*8=192,,197
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,}; // (4*8-1)*8=248,,255
}
    
    CPU::CPU() {
        detail::status.parity = false;
    }
    void CPU::process(uint8_t op) {
        detail::inst[op](op);
    }
    void CPU::reset() {

    }