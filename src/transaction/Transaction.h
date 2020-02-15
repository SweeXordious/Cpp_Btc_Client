//
// Created by chizisch on 2/1/20.
//

#ifndef PSYCHIC_GARBANZO_TRANSACTION_H
#define PSYCHIC_GARBANZO_TRANSACTION_H

#include <stdint-gcc.h>
#include <src/transaction/txInput/TransactionInput.h>
#include <src/transaction/txOutput/TransactionOutput.h>

/*
 * Regular transactions structure:
 *  - Version
 *  - NumberOfInputs
 *  - CollectionOfInputs:
 *      - hash of transaction
 *      - Output index: vout
 *      - sequence number
 *      - SignatureScript: signature verifying ownership of previous output: Data parameters that satisfy the conditionals in the pubkey script: <pubKeyUnhashed> <Sig in Secp256k1>:
 *          - txid
 *          - output index of previous transaction
 *          - previous output's pubkey script
 *          - the pubkeyScript created to let the next recipient spend this transaction's output.
 *          - amount of satoshis to spend to the next recipient.
 *  - NumberOfOutputs
 *  - CollectionOfOutputs:
 *      - value
 *      - index: vout
 *      - scriptPubKey
 *  - LockTimestamp
 *
 *
 */

class Transaction {
private:
    int32_t version;
    int txInCount;
    TransactionInput inputs;
    int txOutCount;
    TransactionOutput outpus;
    uint32_t locktime;

public:
    Transaction(){}

    Transaction(int32_t version, int txInCount, const TransactionInput &inputs, int txOutCount,
                const TransactionOutput &outpus, uint32_t locktime) : version(version), txInCount(txInCount),
                                                                      inputs(inputs), txOutCount(txOutCount),
                                                                      outpus(outpus), locktime(locktime) {}

    void setVersion(int32_t version) {
        Transaction::version = version;
    }

    int getTxInCount() const {
        return txInCount;
    }

    void setTxInCount(int txInCount) {
        Transaction::txInCount = txInCount;
    }

    const TransactionInput &getInputs() const {
        return inputs;
    }

    void setInputs(const TransactionInput &inputs) {
        Transaction::inputs = inputs;
    }

    int getTxOutCount() const {
        return txOutCount;
    }

    void setTxOutCount(int txOutCount) {
        Transaction::txOutCount = txOutCount;
    }

    const TransactionOutput &getOutpus() const {
        return outpus;
    }

    void setOutpus(const TransactionOutput &outpus) {
        Transaction::outpus = outpus;
    }

    uint32_t getLocktime() const {
        return locktime;
    }

    void setLocktime(uint32_t locktime) {
        Transaction::locktime = locktime;
    }


    bool operator==(const Transaction &rhs) const {
        return version == rhs.version &&
               txInCount == rhs.txInCount &&
               inputs == rhs.inputs &&
               txOutCount == rhs.txOutCount &&
               outpus == rhs.outpus &&
               locktime == rhs.locktime;
    }

    bool operator!=(const Transaction &rhs) const {
        return !(rhs == *this);
    }


};


#endif //PSYCHIC_GARBANZO_TRANSACTION_H
