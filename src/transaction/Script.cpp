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

        std::cout << op << endl;

        if(op == optypeToString(OP_CHECKSIG)){
            std::cout << "In OP_CHECKSIG"  << endl;

            std::string sig = execStack.top();
            execStack.pop();
            std::string pkey = execStack.top();
            execStack.pop();

            std::cout << sig << std::endl;
            std::cout << pkey << std::endl;

            if(sig.size() == -5) throw "Error: Signature size is incorrect";
            if(pkey.size() != 64) throw "Error: Public key size is incorrect";

            unsigned char *ucSig = (unsigned char*) malloc(pkey.size()+1);
            std::copy(sig.c_str(), sig.c_str() + sizeof(sig.c_str()),ucSig );

            unsigned char *ucPkey = (unsigned char*) malloc(sig.size()+1);
            std::copy(pkey.c_str(),pkey.c_str() + sizeof(pkey.c_str()), ucPkey);


            std::cout << ucSig << std::endl;
            std::cout << ucPkey << std::endl;

            secp256k1_context *verifyContext = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
            secp256k1_context *noneContext = secp256k1_context_create(SECP256K1_CONTEXT_NONE);


            secp256k1_pubkey pubkey;
            if(secp256k1_ec_pubkey_parse(noneContext, &pubkey, ucPkey, sizeof(ucPkey)) == 0) throw "Error: Public key parsing failed!";

            secp256k1_ecdsa_signature signature;
            if(secp256k1_ecdsa_signature_parse_der(noneContext, &signature, ucSig, sizeof(ucSig)) == 0) throw "Error: Signature parsing failed";

            std:: string hashed_tx = sha256String(tx);
            unsigned char* msg32 = (unsigned char*) malloc(64 * sizeof(unsigned char));
            std::copy(hashed_tx.c_str(), hashed_tx.c_str() + sizeof(hashed_tx.c_str()), msg32);

            std::cout << msg32 << endl;

            if (secp256k1_ecdsa_verify(verifyContext, &signature, msg32, &pubkey) == 1) execStack.push("true");
            else execStack.push("false");
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
            std::cout << "Before: " << currentOp << std::endl;
            execStack.pop();
            std::string doubleHash = ripemd160String(sha256String(currentOp));
            execStack.push(doubleHash);
            std::cout << doubleHash << std::endl;
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

