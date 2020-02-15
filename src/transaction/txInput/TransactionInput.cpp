//
// Created by chizisch on 2/9/20.
//

#include "TransactionInput.h"

using namespace std;

TransactionInput::TransactionInput() {}

TransactionInput::TransactionInput(const string &hashKey, uint32_t index, const string &sigScript,
                                   const string &signature, uint32_t sequenceNumber) : hashKey(hashKey), index(index),
                                                                                       sigScript(sigScript),
                                                                                       signature(signature),
                                                                                       sequenceNumber(sequenceNumber) {}

bool TransactionInput::operator==(const TransactionInput &rhs) const {
    return hashKey == rhs.hashKey &&
           index == rhs.index &&
           sigScript == rhs.sigScript &&
           signature == rhs.signature &&
           sequenceNumber == rhs.sequenceNumber;
}

bool TransactionInput::operator!=(const TransactionInput &rhs) const {
    return !(rhs == *this);
}
