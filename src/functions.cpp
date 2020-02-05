//
// Created by chizisch on 28‏/1‏/2020.
//

#include <string>
#include <cstring>
#include <include/includes.h>
#include "functions.h"


int dummydum (std::string str) {
    if (str == "rachid")
        return 13;
    else
        return 14;
}

std::array<char, HASH_ARRAY_SIZE> stringToArray(std::string input) {
    std::array<char, HASH_ARRAY_SIZE> buf{};

    char hash_char64[HASH_ARRAY_SIZE];
    strcpy(hash_char64, input.c_str());

    for (int i = 0; i < HASH_ARRAY_SIZE; i++)
        buf[i] = hash_char64[i];

    return buf;
}
