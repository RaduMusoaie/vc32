#include <cassert>
#include <core/cpu.hpp>

int main() {

    Cpu cpu;

    cpu.write_register(3, 12);
    cpu.write_register(5, 13);

    assert(cpu.read_register(3) == 12);
    assert(cpu.read_register(5) == 13);

}