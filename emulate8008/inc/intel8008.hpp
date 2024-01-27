/* An Intel8008 CPU has 7 registers A, B, C, D, E, H, L, Stac, Stack index, PC and
 * status flags (carry, zero, sign, parity)
 * The instruction decoding uses a sparse array of functionpointers to the microcode functions.
 * CPU::process calls the microcode by lookup _inst[op](op);
 * The CPU shall output the PC and control signals, the
*/
#include "array"
#include <cstdint>
#include <cassert>
#include <functional>
#include <iostream>

using RAM = std::array<uint8_t, 8>;
using STACK = std::array<uint16_t, 8>;
using REGISTER = uint8_t;
using Decode = std::array<std::function<void(uint8_t op)>, 256>;

// REGISTER hl[2];
// uint16_t HL(){return hl[1]<<8|hl[0];}

/*
 * Istructions
 * There are five groups of instructions (49):
 * Index register(7), Accumulator (28), PC & Stack control(10), I/O (2), Machine Instr (2).
 * 
 * LrI, LMI, Inc, Dec, ADI, ACI, SUI, SBI, NDI, XRI, ORI, CPI, RLC, RRC, RAL, RAR, RET, RFc, RTc, RST, HLT: 00
 * JMP, JFc, JTc, CAL, , CFc, CTcin & out: 01
 * ADr, ADM, ACr, ACM, SUr, SUM, SBr, SBM: 10
 * Lr1r2, LrM, LMr: 11
 * 
 * Load instructions do not affect flags
 * Inc, Dec affect all flags
*/
/* Registers
 * SSS or DDD
 * A - 0 (Acc)
 * B - 1
 * C - 2
 * D - 3
 * E - 4
 * H - 5
 * L - 6
 * Mem - 7 
*/
namespace detail {
    
}
class CPU {
    public:
    CPU();
    /* Process shall put PC on adr bus, Read instruction at that adr, decode insr,
    *  read remaining data, execute instr, update flags, update PC */
    void process();
    void reset();

    struct Status{
        bool carry;
        bool zero;
        bool sign;
        bool parity;
    };
    union alignas(8) Adr{
        uint16_t HL : 16;
        struct {
        REGISTER L : 8;
        REGISTER H : 8;
        }bytes;
    };
    REGISTER A, B, C, D, E; // A is Acc
    uint16_t programcounter = 0;
    uint8_t stackIndex = 0;
    STACK Stack;
    Status status;
    Adr adr;
};
