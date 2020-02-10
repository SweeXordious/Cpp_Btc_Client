//
// Created by chizisch on 2/1/20.
//

#ifndef PSYCHIC_GARBANZO_TRANSACTION_H
#define PSYCHIC_GARBANZO_TRANSACTION_H
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

};


#endif //PSYCHIC_GARBANZO_TRANSACTION_H
