//
// Created by chizisch on 2/1/20.
//

#ifndef PSYCHIC_GARBANZO_MERKLETREE_H
#define PSYCHIC_GARBANZO_MERKLETREE_H

#include "include/includes.h"


/*
 * How to Use:
 *  - Create your merkle tree structure
 *  - add the wanted transaction hashes using the add
 */

class MerkleTree {
private:
    std::vector<std::string > txs_hash;
    std::string root;
    int size;

public:
    MerkleTree();
    void addTx(const std::string& tx_hash);
    void addTx(const std::array<char, HASH_ARRAY_SIZE> tx_hash);

    void calculateRoot();

    const std::vector<std::string> &getTxsHash() const;

    const std::string &getRoot() const ;
    const char* getRootChar() const;
    const std::array<char, HASH_ARRAY_SIZE> getRootArray() const;

    int getSize() const;

};


#endif //PSYCHIC_GARBANZO_MERKLETREE_H
