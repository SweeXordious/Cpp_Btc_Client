//
// Created by chizisch on 2/1/20.
//

#ifndef PSYCHIC_GARBANZO_BLOCKHEADER_H
#define PSYCHIC_GARBANZO_BLOCKHEADER_H

#include "include/includes.h"
using namespace std;

class BlockHeader {
private:
    int32_t version;
    array<char, HASH_ARRAY_SIZE> prev_block_header;
    array<char, HASH_ARRAY_SIZE> merkle_root;
    uint32_t time;
    uint32_t nBits;
    uint32_t nonce;
public:
    BlockHeader() {}

    BlockHeader(int32_t version, array<char, HASH_ARRAY_SIZE> prevBlockHeader, array<char, HASH_ARRAY_SIZE> merkleRoot, uint32_t time, uint32_t nBits,
                uint32_t nonce);


    int32_t getVersion() const;

    void setVersion(int32_t version);

    array<char, HASH_ARRAY_SIZE> getPrevBlockHeader() const;

    array<char, HASH_ARRAY_SIZE> getMerkleRoot() const;

    uint32_t getTime() const;

    void setTime(uint32_t time);

    uint32_t getNBits() const;

    void setNBits(uint32_t nBits);

    uint32_t getNonce() const;

    void setNonce(uint32_t nonce);

    void setPrev_block_header(array<char, HASH_ARRAY_SIZE> pvh) {
        prev_block_header = pvh;
    }

    void setMerkle_root(array<char, HASH_ARRAY_SIZE> mr){
        merkle_root = mr;
    }

    bool operator==(const BlockHeader &rhs) const;

    bool operator!=(const BlockHeader &rhs) const;
};


#endif //PSYCHIC_GARBANZO_BLOCKHEADER_H
