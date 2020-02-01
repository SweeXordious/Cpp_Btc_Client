//
// Created by chizisch on 2/1/20.
//

#include <iostream>
#include "MerkleTree.h"

MerkleTree::MerkleTree(): size(0) {
    txs_hash = std::vector<std::string>();
    root = std::string();
}

void MerkleTree::addElement(const std::string& tx_hash) {

    // Check if provided tx_hash isn't null
    if(tx_hash.empty()) {
        throw "Hash not calculated correctly (empty string)";
    }

    txs_hash.push_back(tx_hash);
    std::sort(txs_hash.begin(), txs_hash.end());
    size++;
}

std::string MerkleTree::calculateRoot() {

    // If the number of transactions is not even, we double the last transaction
    using namespace std;
    vector<string> temp = txs_hash;
    vector<string> target;

    do {
        target = vector<string>();
        for(auto hash = temp.begin(); hash != temp.end(); ++hash){
            string concat = "";
            if (next(hash) == temp.end()){
                concat = *hash + *hash;
            } else{
                string a = *(hash++);
                string b = *(hash);
                concat = a + b;
            }
            target.push_back(sha256String(concat));
        }
        temp = target;
    } while(target.size() > 1);

    root = target[0];
    return root;
}




const std::vector<std::string> &MerkleTree::getTxsHash() const {
    return txs_hash;
}

const std::string &MerkleTree::getRoot() const {
    return root;
}

int MerkleTree::getSize() const {
    return size;
}


