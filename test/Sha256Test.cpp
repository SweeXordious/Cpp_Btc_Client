//
// Created by chizisch on 1/31/20.
//

#include "include/includes.h"


TEST_CASE("sha256 to String conversion test"){
    CHECK(sha256String("test") == "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08");
}

TEST_CASE("Sha256 to Mpz conversion test"){
    mpz_t expected_output;
    char const string_output[]= "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08";
    mpz_init(expected_output);
    mpz_set_str(expected_output, string_output, 16);

    mpz_t actual_output;
    mpz_init(actual_output);
    sha256Mpz("test", actual_output);

    CHECK(mpz_cmp(expected_output, actual_output) == 0);
}
