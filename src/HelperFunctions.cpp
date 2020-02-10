//
// Created by chizisch on 28‏/1‏/2020.
//

#include <string>
#include <cstring>
#include <include/includes.h>
#include "HelperFunctions.h"


int dummydum (std::string str) {
    if (str == "rachid")
        return 13;
    else
        return 14;
}

std::string optypeToString(opcodetype op){
    switch(op){
        case OP_EQUALVERIFY:
            return "OP_EQUALVERIFY";
        case OP_CHECKSIG:
            return "OP_CHECKSIG";
        case OP_HASH160:
            return "OP_HASH160";
        case OP_DUP:
            return "OP_DUP";
        default:
            return "Unknown OP_CODE";
    }
}

opcodetype stringToOpCode(std::string op){
    if (op.compare("OP_EQUALVERIFY") == 0 ) return OP_EQUALVERIFY;
    else if (op.compare("OP_CHECKSIG") == 0) return OP_CHECKSIG;
    else if (op.compare("OP_HASH160") == 0) return OP_HASH160;
    else if (op.compare("OP_DUP") == 0) return OP_DUP;
    else return OP_UNKNOWN;

}

std::array<char, HASH_ARRAY_SIZE> stringToArray(std::string input) {
    std::array<char, HASH_ARRAY_SIZE> buf{};

    char hash_char64[HASH_ARRAY_SIZE];
    strcpy(hash_char64, input.c_str());

    for (int i = 0; i < HASH_ARRAY_SIZE; i++)
        buf[i] = hash_char64[i];

    return buf;
}
