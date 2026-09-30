#include <catch2/catch_test_macros.hpp>
#include <core/cpu.hpp>


TEST_CASE("CPU registers can be written and read")
{
    Cpu cpu;

    cpu.write_register(3, 12);
    cpu.write_register(5, 13);

    REQUIRE(cpu.read_register(3) == 12);
    REQUIRE(cpu.read_register(5) == 13);
}

TEST_CASE("New CPU registers start at zero")
{
    Cpu cpu;

    REQUIRE(cpu.read_register(0) == 0);
    REQUIRE(cpu.read_register(1) == 0);
    REQUIRE(cpu.read_register(2) == 0);
}

TEST_CASE("Register out of bounds")
{

    Cpu cpu;

    REQUIRE_THROWS_AS(cpu.read_register(45), InvalidRegisterException);
    REQUIRE_THROWS_AS(cpu.read_register(32), InvalidRegisterException);
    REQUIRE_THROWS_AS(cpu.read_register(255), InvalidRegisterException);

    REQUIRE_THROWS_AS(cpu.write_register(32, 12), InvalidRegisterException);
    REQUIRE_THROWS_AS(cpu.write_register(45, 134), InvalidRegisterException);
    REQUIRE_THROWS_AS(cpu.write_register(255, 1232), InvalidRegisterException);

}

TEST_CASE("Register in bounds")
{

    Cpu cpu;

    REQUIRE_NOTHROW(cpu.read_register(0));
    REQUIRE_NOTHROW(cpu.read_register(31));

    REQUIRE_NOTHROW(cpu.write_register(0, 32));
    REQUIRE_NOTHROW(cpu.write_register(31, 41));

}