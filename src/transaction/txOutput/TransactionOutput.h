//
// Created by chizisch on 2/15/20.
//

#ifndef PSYCHIC_GARBANZO_TRANSACTIONOUTPUT_H
#define PSYCHIC_GARBANZO_TRANSACTIONOUTPUT_H


#include <stdint-gcc.h>
#include <string>

class TransactionOutput {
private:
    int64_t  value;
    std::string pkScript;

public:
    TransactionOutput();

    int64_t getValue() const {
        return value;
    }

    void setValue(int64_t value) {
        TransactionOutput::value = value;
    }

    const std::string &getPkScript() const {
        return pkScript;
    }

    void setPkScript(const std::string &pkScript) {
        TransactionOutput::pkScript = pkScript;
    }

    bool operator==(const TransactionOutput &rhs) const;

    bool operator!=(const TransactionOutput &rhs) const;

    TransactionOutput(int64_t value, const std::string &pkScript);
};


#endif //PSYCHIC_GARBANZO_TRANSACTIONOUTPUT_H
