//
// Created by chizisch on 2/9/20.
//

#include <iostream>
#include "Script.h"


Script::Script(std::string _tx): tx(_tx) {
    script = std::vector<std::string>();
}


bool Script::execute() {

    if(script.size() == 0) throw "Error: The stack containing the script is empty!";

    std::stack<std::string, std::deque<std::string>> execStack;

    for (auto op : script) {

        if(op == optypeToString(OP_CHECKSIG)){

            // Pop elements from the stack
            std::string pkey = execStack.top();
            execStack.pop();
            std::string sig = execStack.top();
            execStack.pop();

            // because we are dealing with uncompressed serialized public keys
            if(pkey.size() != 65) throw "Error: Public key size is incorrect";

/*
            // Creating C-type strings for the signature
            unsigned char ucSig[pkey.size()+1] = {0};
            const char* cSig = sig.c_str();
            std::copy(cSig, cSig + strlen(cSig),ucSig);

            // Creating C-type strings for the pkey
            unsigned char *ucPkey = (unsigned char*) malloc(sig.size()+1);
            const char* cPKey = pkey.c_str();
            std::copy(cPKey,cPKey + pkey.size(), ucPkey);

            secp256k1_context *verifyContext = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
            secp256k1_context *noneContext = secp256k1_context_create(SECP256K1_CONTEXT_NONE);

            // Parsing pkey and signature
            secp256k1_pubkey pubkey;
            if(secp256k1_ec_pubkey_parse(noneContext, &pubkey, ucPkey, pkey.size()) == 0) throw "Error: Public key parsing failed!";

            secp256k1_ecdsa_signature signature;
            if(sig != "wrong_sig" && secp256k1_ecdsa_signature_parse_der(noneContext, &signature, ucSig, sig.size()) == 0 ) throw "Error: Signature parsing failed";

            // Creating C-type strings for the transaction hash
            std:: string hashed_tx = sha256String(tx);
            const char* cHashed_tx = hashed_tx.c_str();
            unsigned char* msg32 = (unsigned char*) malloc(hashed_tx.size() * sizeof(unsigned char));
            std::copy(cHashed_tx, cHashed_tx + hashed_tx.size(), msg32);

            // Verifying signature with pkey

            if (secp256k1_ecdsa_verify(verifyContext, &signature, msg32, &pubkey) == 1) execStack.push("true");
            else execStack.push("false");

            // Cleaning out
            //secp256k1_context_destroy(verifyContext);
            //secp256k1_context_destroy(noneContext);
            */
        }
        else if (op == optypeToString(OP_DUP)) execStack.push(execStack.top());
        else if(op == optypeToString(OP_EQUALVERIFY)) {
            std::string first = execStack.top();
            execStack.pop();
            std::string second = execStack.top();
            execStack.pop();
            if (first != second) return false;
        } else if (op == optypeToString(OP_HASH160)) {
            std::string currentOp = execStack.top();
            execStack.pop();
            std::string doubleHash = ripemd160String(sha256String(currentOp));
            execStack.push(doubleHash);
        }
        else execStack.push(op);
    }

    return execStack.top() == "true";
}

void Script::fillP2pkh(std::string pubKeyHash, std::string pubkey, std::string sig) {
    script.push_back(sig);
    script.push_back(pubkey);
    script.push_back(optypeToString(OP_DUP));
    script.push_back(optypeToString(OP_HASH160));
    script.push_back(pubKeyHash);
    script.push_back(optypeToString(OP_EQUALVERIFY));
    script.push_back(optypeToString(OP_CHECKSIG));

}

