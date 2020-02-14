//
// Created by chizisch on 2/11/20.
//

#include <iostream>
#include <iomanip>
#include "include/includes.h"

TEST_CASE("Testing p2pkh with an empty script") {
    Script s = Script("A script should be here");
    CHECK_THROWS(s.execute());
}

TEST_CASE("Testing p2pkh with a script: false pubkeyhash") {
    Script s = Script("A script should be here");
    s.fillP2pkh(ripemd160String(sha256String("013e8c5dcb8e35670de496b57c1fa4366800ce3be5fded9b8800759881bc8da2e5")), "033e8c5dcb8e35670de496b57c1fa4366800ce3be5fded9b8800759881bc8da2e5", "304502203f004eeed0cef2715643e2f25a27a28f3c578e94c7f0f6a4df104e7d163f7f8f022100b8b248c1cfd8f77a0365107a9511d759b7544d979dd152a955c867afac0ef78601");
    CHECK(s.execute() == false);
}

TEST_CASE("Testing p2pkh with a script: wrong pubkey format") {

    Script s = Script("A script should be here");
    CHECK_THROWS(s.execute());
    s.fillP2pkh(ripemd160String(sha256String("033e8c5dcb8e35670de496b57c1fa4366800ce3be5fded9b8800759881bc8da2e5")), "033e8c5dcb8e35670de496b57c1fa4366800ce3be5fded9b8800759881bc8da2e5", "304502203f004eeed0cef2715643e2f25a27a28f3c578e94c7f0f6a4df104e7d163f7f8f022100b8b248c1cfd8f77a0365107a9511d759b7544d979dd152a955c867afac0ef78601");
    CHECK_THROWS(s.execute());
}

TEST_CASE("Testing p2pkh with a script: correct pkey and wrong signature") {

    // Creating a 32-bytes private key
    std::string privateKey = "7e6d4ec4f0ed1c8cff56356fafb394970fa0c8aa83a1e351f9f4b9fbf327250c";
    char cPrivateKey[32];
    hexToBytes(privateKey, cPrivateKey, privateKey.length());


    // creating public key from it
    secp256k1_context  *signingContext = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    secp256k1_pubkey pkey;
    unsigned char seckey[32];
    std::copy(cPrivateKey, cPrivateKey + 32, seckey);

    // Checking the creation of the public key
    if (secp256k1_ec_pubkey_create(signingContext, &pkey, reinterpret_cast<const unsigned char *>(&seckey)) == 0) throw "Error: Public key creation failed!";


    // Serializing the public key
    secp256k1_context *noneContext = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    unsigned char output[65];
    std::size_t outputLen = 65;
    secp256k1_ec_pubkey_serialize(noneContext, reinterpret_cast<unsigned char *>(&output), &outputLen, &pkey, SECP256K1_EC_UNCOMPRESSED);


    // Creating a script with corresponding pkey and pkhash
    Script s = Script("A script should be here");
    s.fillP2pkh(ripemd160String(sha256String(std::string(reinterpret_cast<const char *>(output)))),
                std::string(reinterpret_cast<const char *>(output)),
                "wrong_sig");

    CHECK(s.execute() == false);
}