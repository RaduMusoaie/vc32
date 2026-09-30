#include <iostream>

#include <core/cpu.hpp>

int main(){

    std::cout << "Hello, world!";

    Cpu cpu;

    cpu.write_register(3, 12);
    cpu.write_register(5, 13);

    int a = cpu.read_register(3) + cpu.read_register(5);

    std::cout << a;

    return 0;

}