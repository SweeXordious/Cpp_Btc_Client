//
// Created by chizisch on 2/15/20.
//

#ifndef PSYCHIC_GARBANZO_TXINPUTBUILDER_H
#define PSYCHIC_GARBANZO_TXINPUTBUILDER_H

#include "src/transaction/txInput/TransactionInput.h"
#include <string>

class TxInputBuilder {
private:
    std::string hashKey;
    uint32_t index;
    std::string sigScript;
    std::string signature;
    uint32_t sequenceNumber;
    TransactionInput txInput;

public:
    TxInputBuilder() {}

    TransactionInput build(){
        txInput = TransactionInput(hashKey, index, sigScript, signature, sequenceNumber);
        return txInput;
    }

    TxInputBuilder& setHashKey(const std::string &hashKey) {
        TxInputBuilder::hashKey = hashKey;
        return *this;
    }

    TxInputBuilder& setIndex(uint32_t index) {
        TxInputBuilder::index = index;
        return *this;
    }

    TxInputBuilder& setSigScript(const std::string &sigScript) {
        TxInputBuilder::sigScript = sigScript;
        return *this;
    }

    TxInputBuilder& setSignature(const std::string &signature) {
        TxInputBuilder::signature = signature;
        return *this;
    }

    TxInputBuilder& setSequenceNumber(uint32_t sequenceNumber) {
        TxInputBuilder::sequenceNumber = sequenceNumber;
        return *this;
    }
};


#endif //PSYCHIC_GARBANZO_TXINPUTBUILDER_H
