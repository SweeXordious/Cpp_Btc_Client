//
// Created by chizisch on 1/31/20.
//

#include <iostream>
#include "include/includes.h"


TEST_CASE("sha256 to String conversion test"){
    CHECK(sha256String("test") == "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08");
}

TEST_CASE("Sha256 to Mpz conversion test"){
    mpz_class expected_output = mpz_class();
    mpz_class actual_output = mpz_class();

    char const string_output[]= "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08";
    expected_output.set_str(string_output, 16);

    actual_output = sha256Mpz("test");

    CHECK(expected_output == actual_output);
}

TEST_CASE("Sha256 to Array conversion test"){
    std::array<char, HASH_ARRAY_SIZE> expected_output {
        '9', 'f', '8', '6', 'd', '0', '8', '1', '8', '8', '4', 'c', '7', 'd', '6',
        '5', '9', 'a', '2', 'f', 'e', 'a', 'a', '0', 'c', '5', '5', 'a', 'd', '0',
        '1', '5', 'a', '3', 'b', 'f', '4', 'f', '1', 'b', '2', 'b', '0', 'b', '8',
        '2', '2', 'c', 'd', '1', '5', 'd', '6', 'c', '1', '5', 'b', '0', 'f', '0',
        '0', 'a', '0', '8' }
    ;
    std::array<char,HASH_ARRAY_SIZE> actual_output{};

    actual_output = sha256Array("test");

    CHECK(actual_output == expected_output);
}