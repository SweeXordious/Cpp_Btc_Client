#include <iostream>
#include <deque>
#include <stack>
#include <iomanip>

#include "include/includes.h"
using namespace std;






int main(int argc, char* const argv[]) {
    std::cout << "Hello World!" << std::endl;
    return 0;

/*
    std::string input = "1ab3cf";
    char bytesInput[input.length()/2] = {0};

    hexToBytes(input, bytesInput, input.length());

    unsigned char bytesOutput[input.length()];
    memcpy(bytesOutput, bytesInput,input.length());


    std::string hexOutput = bytesToHexString(bytesOutput, sizeof(bytesInput) / sizeof(char));

    std::cout << hexOutput << std::endl;

    return 0;


    // private key
    std::string privateKey = "0xbaca891f5f0285e043496843d82341d15533f016c223d114e1e4dfd39e60ecb0";
    unsigned char cPrivateKey[64];
    memcpy(cPrivateKey,privateKey.c_str(), 64);
    char *result = (char*) malloc(64 * sizeof(char));
    memcpy(result, cPrivateKey, strlen(reinterpret_cast<const char *>(cPrivateKey)));

    std::cout << strlen(result) << std::endl;
    std::cout << result;


    std::string privateKey = "7e6d4ec4f0ed1c8cff56356fafb394970fa0c8aa83a1e351f9f4b9fbf327250c";
    // const char* cPrivateKey = HexToBytes(privateKey);
    char cPrivateKey[32];
    hexToBytes(privateKey, cPrivateKey, privateKey.length());


    // creating public key from it
    secp256k1_context  *signingContext = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    secp256k1_pubkey pkey;

    unsigned char seckey[32];
    std::copy(cPrivateKey, cPrivateKey + 32, seckey);


    if (secp256k1_ec_pubkey_create(signingContext, &pkey, reinterpret_cast<const unsigned char *>(&seckey)) == 0) throw "Creation error";


    // print the result in hex
    std::cout << bytesToHexString(pkey.data, 64) << std::endl;


    // parsing the result
    //std::string pkey_data  = ss.str();
    secp256k1_context *noneContext = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    secp256k1_pubkey pubkey;


/** Serialize a pubkey object into a serialized byte sequence.
 *
 *  Returns: 1 always.
 *  Args:   ctx:        a secp256k1 context object.
 *  Out:    output:     a pointer to a 65-byte (if compressed==0) or 33-byte (if
 *                      compressed==1) byte array to place the serialized key
 *                      in.
 *  In/Out: outputlen:  a pointer to an integer which is initially set to the
 *                      size of output, and is overwritten with the written
 *                      size.
 *  In:     pubkey:     a pointer to a secp256k1_pubkey containing an
 *                      initialized public key.
 *          flags:      SECP256K1_EC_COMPRESSED if serialization should be in
 *                      compressed format, otherwise SECP256K1_EC_UNCOMPRESSED.

    SECP256K1_API int secp256k1_ec_pubkey_serialize(
            const secp256k1_context* ctx,
            unsigned char *output,
            size_t *outputlen,
            const secp256k1_pubkey* pubkey,
            unsigned int flags
    ) SECP256K1_ARG_NONNULL(1) SECP256K1_ARG_NONNULL(2) SECP256K1_ARG_NONNULL(3) SECP256K1_ARG_NONNULL(4);


    //secp256k1_context context;
    unsigned char output[65];
    std::size_t outputLen = 65;

    secp256k1_ec_pubkey_serialize(noneContext, reinterpret_cast<unsigned char *>(&output), &outputLen, &pkey, SECP256K1_EC_UNCOMPRESSED);

    std::cout << output << " : " << outputLen << std::endl;

    if (secp256k1_ec_pubkey_parse(noneContext, &pubkey, output, 65) == 0) std::cout << "Couldnt parse using pkey.data" << std::endl;
//    if (secp256k1_ec_pubkey_parse(noneContext, &pubkey, pkey_data.c_str(), pkey_data.size()) == 0) std::cout << "Couldnt parse using hex public key " << std::endl;

    std::cout << bytesToHexString(pubkey.data, 65);

    return 0;


    /*
    // private key
    std::string privateKey = "baca891f5f0285e043496843d82341d15533f016c223d114e1e4dfd39e60ecb0";
    const char* cPrivateKey = privateKey.c_str();

    // creating public key from it
    secp256k1_context  *signingContext = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    secp256k1_context *ctx;
    secp256k1_pubkey pkey;

    unsigned char *seckey = (unsigned char*) malloc(privateKey.size() * sizeof(unsigned char));
    std::copy(cPrivateKey, cPrivateKey + privateKey.size(), seckey);

    if(secp256k1_ec_seckey_verify(ctx, seckey) == 0) std::cout << "Seckey Verification failed" << std::endl;
    else std::cout << "SecKey verifaction succeded" << std::endl;

    if (secp256k1_ec_pubkey_create(signingContext, &pkey, seckey) == 0) throw "Creation error";

    // print the result in hex
    std::stringstream ss;
    for (int i = 0; i < 64; ++i)
    {
        ss <<  std::setfill('0') << std::setw(2) << std::hex << (0xff & (unsigned int)pkey.data[i]);
    }

    std::cout << ss.str() << std::endl;

    // parsing the result
    std::string pkey_data  = ss.str();

    secp256k1_context *noneContext = secp256k1_context_create(SECP256K1_CONTEXT_NONE);


    secp256k1_pubkey pubkey;
    if (secp256k1_ec_pubkey_parse(noneContext, &pubkey, pkey.data, 64) == 0) std::cout << "Couldnt parse using pkey.data" << std::endl;

    std::cout << pubkey.data << std::endl;

    if (secp256k1_ec_pubkey_parse(noneContext, &pubkey, reinterpret_cast<const unsigned char *>(pkey_data.c_str()), 64) == 0) std::cout << "Couldnt parse using hex public key " << std::endl;

    std::cout << pubkey.data << std::endl;
    return 0;

     */
}
