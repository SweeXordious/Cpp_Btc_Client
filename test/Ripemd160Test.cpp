//
// Created by chizisch on 2/11/20.
//

#include "include/includes.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

TEST_CASE("Testing RIPEMD160 using strings"){
    CHECK(ripemd160String("9C1185A5C5E9FC54612808977EE8F548B2258D31") == "b621875736b8d954274b63d725fac3391cb19e47");
}