#ifndef CPU_HPP
#define CPU_HPP

#include <stdint.h>
#include <stdexcept>

class InvalidRegisterException: std::out_of_range
{

    public:
        InvalidRegisterException()
            : std::out_of_range("Invalid register index")
        {

        }

};

#define CPU_NUMBER_OF_REGISTERS 32

class Cpu {


    private:
        int32_t registers[CPU_NUMBER_OF_REGISTERS];

    public:

    Cpu() {

        for (int8_t i = 0; i < 32; i++)
            registers[i] = 0;

    }

    int32_t read_register(uint8_t reg) {

        if(reg >= CPU_NUMBER_OF_REGISTERS) {
            
            throw InvalidRegisterException();
        }


        return this->registers[reg];

    }

    void write_register(uint8_t reg, int32_t value) {

        if(reg >= CPU_NUMBER_OF_REGISTERS) {

            throw InvalidRegisterException();
        }

        this->registers[reg] = value;

    }

};


#endif // CPU_HPP
