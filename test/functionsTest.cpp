//
// Created by chizisch on 28‏/1‏/2020.
//
#include "libs/catch2/catch.hpp"
#include "include/functions.h"


TEST_CASE("Dummy Tests", "Second Arg"){
    CHECK(dummydum("rachid") == 12);
    CHECK_FALSE(dummydum("hamid") == 13);
}
