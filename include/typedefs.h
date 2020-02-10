//
// Created by chizisch on 1/31/20.
//

#ifndef PSYCHIC_GARBANZO_TYPEDEFS_H
#define PSYCHIC_GARBANZO_TYPEDEFS_H

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef unsigned long long uint64;


enum opcodetype
{
    OP_DUP = 0,
    OP_HASH160 = 1,
    OP_EQUALVERIFY = 2,
    OP_CHECKSIG = 3,
    OP_UNKNOWN = 4
};


#endif //PSYCHIC_GARBANZO_TYPEDEFS_H
