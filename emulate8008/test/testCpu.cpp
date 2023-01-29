#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "scelbi.hpp"
#include "doctest.h"

namespace detail {
extern Adr adr;
}

TEST_CASE("case") {
    RAM ram{00,01,02,03,04,05,06,010};
    CPU intel8008;
    auto *scelbi = new Scelbi(intel8008, ram);
  SUBCASE("reset") {
        scelbi->reset();
        CHECK(true);
    }
    SUBCASE("execute nop") {
        intel8008.process(0b11000000); // NOP, aka LAA
    }
    SUBCASE("sub") {
        using namespace detail;
        adr.HL = static_cast<uint16_t>(0xFF00);
        CHECK_EQ(adr.bytes.H, static_cast<uint16_t>(0xFF)); // 0!
        CHECK_EQ(adr.bytes.L, 0);
        adr.HL = static_cast<uint16_t>(0x00FF);
        CHECK_EQ(adr.bytes.H, static_cast<uint16_t>(0x0)); // 0xff!
        CHECK_EQ(adr.bytes.L, static_cast<uint16_t>(0xFF));
        adr.bytes.H = static_cast<REGISTER>(0xFF);
        adr.bytes.L = static_cast<uint16_t>(0x00);
        CHECK_EQ(adr.HL, static_cast<uint16_t>(0xFF00)); // 0!
        adr.bytes.H = static_cast<REGISTER>(0x00);
        adr.bytes.L = static_cast<uint16_t>(0xFF);
        CHECK_EQ(adr.HL, static_cast<uint16_t>(0x00FF));
    }
}
TEST_CASE("case") {
  SUBCASE("sub") {
    }
}