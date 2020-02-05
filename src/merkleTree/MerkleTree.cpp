//
// Created by chizisch on 2/1/20.
//

#include <iostream>
#include "MerkleTree.h"

MerkleTree::MerkleTree(): size(0) {
    txs_hash = std::vector<std::string>();
    root = std::string();
}

void MerkleTree::addTx(const std::string& tx_hash) {

    // Check if provided tx_hash isn't null
    if(tx_hash.empty()) {
        throw "Hash not calculated correctly (empty string)";
    }

    txs_hash.push_back(tx_hash);
    std::sort(txs_hash.begin(), txs_hash.end());
    size++;
}

void MerkleTree::calculateRoot() {

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
}




const std::vector<std::string> &MerkleTree::getTxsHash() const {
    return txs_hash;
}

const std::string &MerkleTree::getRoot() const {
    if(root.empty()){
        throw "Error: Trying to get root of structure before calculting it.";
    }
    return root;
}

int MerkleTree::getSize() const {
    return size;
}

const char* MerkleTree::getRootChar() const {
    if(root.empty()){
        throw "Error: Trying to get root of structure before calculting it.";
    }

    if(root.size() != HASH_ARRAY_SIZE){
        throw "Error: Merkle tree root is incorrect! Try recalculating it!";
    }

    char* rootChar = (char*)malloc(sizeof (char) * HASH_ARRAY_SIZE);
    strcpy(rootChar, root.c_str());

    return rootChar;
}

void MerkleTree::addTx(const std::array<char, HASH_ARRAY_SIZE> tx_hashArray) {
    std::string tx_hash = std::string(tx_hashArray.begin(), tx_hashArray.end());
    addTx(tx_hash);
}

const std::array<char, HASH_ARRAY_SIZE> MerkleTree::getRootArray() const {
    return std::array<char, HASH_ARRAY_SIZE>{stringToArray(root)};
}


