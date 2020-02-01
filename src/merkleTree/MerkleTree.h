//
// Created by chizisch on 2/1/20.
//

#ifndef PSYCHIC_GARBANZO_MERKLETREE_H
#define PSYCHIC_GARBANZO_MERKLETREE_H

#include "include/includes.h"

class MerkleTree {
private:
    std::vector<std::string > txs_hash;
    std::string root;
    int size;

public:
    MerkleTree();
    void addElement(const std::string& tx_hash);
    std::string calculateRoot();

    const std::vector<std::string> &getTxsHash() const;

    const std::string &getRoot() const;

    int getSize() const;

};


#endif //PSYCHIC_GARBANZO_MERKLETREE_H
