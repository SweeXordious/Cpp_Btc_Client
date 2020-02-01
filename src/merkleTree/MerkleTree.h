//
// Created by chizisch on 2/1/20.
//

#ifndef PSYCHIC_GARBANZO_MERKLETREE_H
#define PSYCHIC_GARBANZO_MERKLETREE_H

#include "include/includes.h"

class MerkleTree {
private:
    std::vector<mpz_t > txs_hash;
    mpz_t root;
    int size;

public:
    virtual ~MerkleTree();

public:
    MerkleTree();
    void addElement(const mpz_t tx_hash);


};


#endif //PSYCHIC_GARBANZO_MERKLETREE_H
