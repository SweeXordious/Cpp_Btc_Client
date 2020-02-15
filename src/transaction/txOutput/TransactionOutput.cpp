//
// Created by chizisch on 2/15/20.
//

#include "TransactionOutput.h"

TransactionOutput::TransactionOutput() {}

TransactionOutput::TransactionOutput(int64_t value, const std::string &pkScript) : value(value), pkScript(pkScript) {}


bool TransactionOutput::operator==(const TransactionOutput &rhs) const {
    return value == rhs.value &&
           pkScript == rhs.pkScript;
}

bool TransactionOutput::operator!=(const TransactionOutput &rhs) const {
    return !(rhs == *this);
}
