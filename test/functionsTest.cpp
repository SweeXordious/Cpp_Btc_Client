//
// Created by chizisch on 28‏/1‏/2020.
//
#define CATCH_CONFIG_MAIN
#include "include/includes.h"


TEST_CASE("Dummy Tests", "Second Arg"){
    CHECK(dummydum("rachid") == 13);
    CHECK_FALSE(dummydum("hamid") == 13);
}

TEST_CASE("String to array test"){

    std::array<char, HASH_ARRAY_SIZE> expected_output {
        '9', 'f', '8', '6', 'd', '0', '8', '1', '8', '8', '4', 'c', '7', 'd', '6',
        '5', '9', 'a', '2', 'f', 'e', 'a', 'a', '0', 'c', '5', '5', 'a', 'd', '0',
        '1', '5', 'a', '3', 'b', 'f', '4', 'f', '1', 'b', '2', 'b', '0', 'b', '8',
        '2', '2', 'c', 'd', '1', '5', 'd', '6', 'c', '1', '5', 'b', '0', 'f', '0',
        '0', 'a', '0', '8' }
    ;
    std::array<char, HASH_ARRAY_SIZE> actual_output = stringToArray("9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08");

    CHECK(expected_output == actual_output);
}

TEST_CASE("OP_TYPE to string tests"){
    CHECK(optypeToString(OP_DUP) == "OP_DUP");
    CHECK(optypeToString(OP_CHECKSIG) == "OP_CHECKSIG");
    CHECK(optypeToString(OP_EQUALVERIFY) == "OP_EQUALVERIFY");
    CHECK(optypeToString(OP_HASH160) == "OP_HASH160");
    CHECK(optypeToString(OP_UNKNOWN) == "Unknown OP_CODE");
}

TEST_CASE("String to OP_TYPE tests"){
    CHECK(stringToOpCode("OP_DUP") == OP_DUP);
    CHECK(stringToOpCode("OP_CHECKSIG") == OP_CHECKSIG);
    CHECK(stringToOpCode("OP_EQUALVERIFY") == OP_EQUALVERIFY);
    CHECK(stringToOpCode("OP_HASH160") == OP_HASH160);
    CHECK(stringToOpCode("Unknown OP_CODE") == OP_UNKNOWN);
}

TEST_CASE("Hex to Bytes array Tests with even hex strings") {
    std::string input = "123456789abcde";
    char bytesInput[input.length()/2];

    hexToBytes(input, bytesInput, input.length());

    unsigned char bytesOutput[input.length()/2];
    memcpy(bytesOutput, bytesInput,input.length());


    std::string hexInput = bytesToHexString(bytesOutput, sizeof(bytesOutput) / sizeof(char));

    CHECK(hexInput == input);
}