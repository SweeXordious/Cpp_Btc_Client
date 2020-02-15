//
// Created by chizisch on 2/9/20.
//

#ifndef PSYCHIC_GARBANZO_TRANSACTIONINPUT_H
#define PSYCHIC_GARBANZO_TRANSACTIONINPUT_H

/*
 * A transaction input is a structure that comprises of:
 *  - hash key
 *  - index number
 *  - signature script
 *  - length indicator
 *  - the response script
 *  - input sequence number:A transaction sequence number consists of two parts: a sequence number code followed by a sequential number.
 *      For example, the following transaction sequence numbers might be assigned to consecutive cash receipt transactions: CRJ1, CRJ2, and CRJ3. In this case CRJ is the sequence number code and the numbers 1, 2, 3 are the sequence numbers.
 *      Sequence number codes and their numbering requirements are defined using Ledger Sequences (LEQ).
 *      Uniquely identify a previous output: hash key + index number
 *
 *
 */

#include <string>

class TransactionInput {
private:
    std::string hashKey; // Verify it is 32-bytes size
    uint32_t index; // which output
    std::string sigScript; // Maximum 10,000 bytes in CompactSize uint
    std::string signature;
    uint32_t sequenceNumber;

public:
    TransactionInput(const std::string &hashKey, uint32_t index, const std::string &sigScript, const std::string &signature,
                     uint32_t sequenceNumber);

    TransactionInput();

    const std::string &getHashKey() const {
        return hashKey;
    }

    void setHashKey(const std::string &hashKey) {
        TransactionInput::hashKey = hashKey;
    }

    uint32_t getIndex() const {
        return index;
    }

    void setIndex(uint32_t index) {
        TransactionInput::index = index;
    }

    const std::string &getSigScript() const {
        return sigScript;
    }

    void setSigScript(const std::string &sigScript) {
        TransactionInput::sigScript = sigScript;
    }

    const std::string &getSignature() const {
        return signature;
    }

    void setSignature(const std::string &signature) {
        TransactionInput::signature = signature;
    }

    uint32_t getSequenceNumber() const {
        return sequenceNumber;
    }

    void setSequenceNumber(uint32_t sequenceNumber) {
        TransactionInput::sequenceNumber = sequenceNumber;
    }

    bool operator==(const TransactionInput &rhs) const;

    bool operator!=(const TransactionInput &rhs) const;
};


#endif //PSYCHIC_GARBANZO_TRANSACTIONINPUT_H
