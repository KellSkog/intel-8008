#include "scelbi.hpp"

Scelbi::Scelbi(CPU &cpu, RAM &ram) : _cpu{cpu}, _ram{ram} {}
void Scelbi::reset() {
    _cpu.reset();
}
// template <typename T>
// concept string_convertible = requires(const T& t) {
//     { t.to_string() } -> std::convertible_to<std::string>;
// };