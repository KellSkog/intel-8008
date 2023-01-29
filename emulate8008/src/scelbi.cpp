#include "scelbi.hpp"

    Scelbi::Scelbi(CPU &cpu, RAM &ram) : _cpu{cpu}, _ram{ram} {}
    void Scelbi::reset() {
        _cpu.reset();
    }