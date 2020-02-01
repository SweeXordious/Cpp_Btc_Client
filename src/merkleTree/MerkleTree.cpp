//
// Created by chizisch on 2/1/20.
//

#include "MerkleTree.h"

MerkleTree::MerkleTree() {
    txs_hash = std::vector<mpz_t >();
    mpz_init(root);
}

void MerkleTree::addElement(const mpz_t tx_hash) {

    // Check if provided tx_hash isnt null
    mpz_t zero;
    mpz_init(zero);
    if(mpz_cmp(tx_hash, zero) == 0) {
        mpz_clear(zero);
        throw "Hash not calculated correctly (equals to zero)";
    }

    // Add the tx_hash to the txs_hash vector
    if (size == 0){
        //txs_hash.push_back(tx_hash);
    } else{

    }
}

MerkleTree::~MerkleTree() {
    mpz_clear(root);

    for (auto & tx_hash : txs_hash){
        mpz_clear(tx_hash);
    }
}
