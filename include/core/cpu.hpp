#ifndef CPU_HPP
#define CPU_HPP

#include <stdint.h>

class Cpu {

    private:
        int32_t registers[32];

    public:

    inline int32_t read_register(uint8_t reg) {

        return this->registers[reg];

    }

    inline void write_register(uint8_t reg, int32_t value) {

        this->registers[reg] = value;

    }

};


#endif // CPU_HPP
