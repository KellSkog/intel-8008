#include <functional>

#include "buses.hpp"
// #include "6502.hpp"

/**
 * Bits D6 & D7 selects instruction groups
 * D7,D6
 * 0,0 - LrI, LMI, INr, DCr, ADI, ACI, SUI, SBI, NDI, XRI, ORI, CPI, RLC, RRC, RAL, RAR, RET, RFc, RTc, RST, HLT
 * 0,1 - JMP, JFc, JTc, CAL, CFc, CTc, INP, OUT
 * 1,0 - ADr, ADM, ACr, ACM, SUr, SUM, SBr, SBM, NDr, NDM, XRr, XRM,  ORr, ORM, CPr, CPM
 * 1,1 - Lr1r2, LrM, LMr, HLT
 * 
*/
namespace detail
{
    void LRR(CPU *self) { // Store Accumulator in Memory X-Indexed Absolute 0x9D
        auto adr = read(uint16_t(self->PC + 2)) << 8 | read(uint16_t(self->PC + 1));
        self->PC += 3;
        write(adr + self->X, self->Acc);
    }

}





/* Opcodes

*/