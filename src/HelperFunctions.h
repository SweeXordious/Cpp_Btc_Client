//
// Created by chizisch on 28‏/1‏/2020.
//

#ifndef FIRST_FUNCTIONS_H
#define FIRST_FUNCTIONS_H

#include <array>
#include <string>

int dummydum (std::string str);
std::array<char, HASH_ARRAY_SIZE> stringToArray(std::string input);
std::string optypeToString(opcodetype op);
opcodetype stringToOpCode(std::string op);

#endif //FIRST_FUNCTIONS_H
