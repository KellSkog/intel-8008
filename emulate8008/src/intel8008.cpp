#include "intel8008.hpp"
#include "instructions.hpp"

    namespace detail {
        // Each position corresponds to an opcode and holds an index into executor
        // decoder is a sparse array with all possible 8 bit opcodes
        std::array<uint8_t, 0x100> decoder { 
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 0 - 0x0F
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 0x10 -
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 0x50 -
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 0xA0 -
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        };
        constexpr std::size_t NumberOfOpCodes = 150;
        // Each position holds a pointer to a function for each op code in lexical order
        // executor is a dense array
        std::array<std::function<void (CPU *)>, NumberOfOpCodes> executor {

        };
    

}
    
    CPU::CPU() {
        status.parity = false;
    }
    void CPU::process() {
        auto index = detail::decoder[IR];
        auto instr = detail::executor[index];
        instr(this);
    }
    void CPU::reset() {

    }