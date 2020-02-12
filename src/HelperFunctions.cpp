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
/*
std::string sign(std::string input){

 *
/** Create an ECDSA signature.
 *
 *  Returns: 1: signature created
 *           0: the nonce generation function failed, or the private key was invalid.
 *  Args:    ctx:    pointer to a context object, initialized for signing (cannot be NULL)
 *  Out:     sig:    pointer to an array where the signature will be placed (cannot be NULL)
 *  In:      msg32:  the 32-byte message hash being signed (cannot be NULL)
 *           seckey: pointer to a 32-byte secret key (cannot be NULL)
 *           noncefp:pointer to a nonce generation function. If NULL, secp256k1_nonce_function_default is used
 *           ndata:  pointer to arbitrary data used by the nonce generation function (can be NULL)
 *
 * The created signature is always in lower-S form. See
 * secp256k1_ecdsa_signature_normalize for more details.

    SECP256K1_API int secp256k1_ecdsa_sign(
            const secp256k1_context* ctx,
            secp256k1_ecdsa_signature *sig,
            const unsigned char *msg32,
            const unsigned char *seckey,
            secp256k1_nonce_function noncefp,
            const void *ndata
    ) SECP256K1_ARG_NONNULL(1) SECP256K1_ARG_NONNULL(2) SECP256K1_ARG_NONNULL(3) SECP256K1_ARG_NONNULL(4);



    secp256k1_context *signContext = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    secp256k1_ecdsa_signature sig;
    const unsigned char* msg[32];
    char* hi ="hi";
    std::copy(hi, hi + sizeof(hi), msg);




    secp256k1_ecdsa_sign(signContext, &sig,  )
}

 */