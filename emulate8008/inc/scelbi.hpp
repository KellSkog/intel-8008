#include "intel8008.hpp"

class Scelbi {
    public:
    Scelbi(CPU &cpu, RAM &ram);
    void reset();
    
    private:
    CPU &_cpu;
    RAM &_ram;
};