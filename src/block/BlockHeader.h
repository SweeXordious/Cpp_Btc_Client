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

    bool operator==(const BlockHeader &rhs) const;

    bool operator!=(const BlockHeader &rhs) const;

    int32_t getVersion() const {
        return version;
    }

    void setVersion(int32_t version) {
        BlockHeader::version = version;
    }

    const array<char, HASH_ARRAY_SIZE>& getPrevBlockHeader() const {
        return prev_block_header;
    }

    void setPrevBlockHeader(const array<char, HASH_ARRAY_SIZE> &prevBlockHeader) {
        prev_block_header = prevBlockHeader;
    }

    const array<char, HASH_ARRAY_SIZE>& getMerkleRoot() const {
        return merkle_root;
    }

    void setMerkleRoot(const array<char, HASH_ARRAY_SIZE> &merkleRoot) {
        merkle_root = merkleRoot;
    }

    uint32_t getTime() const {
        return time;
    }

    void setTime(uint32_t time) {
        BlockHeader::time = time;
    }

    uint32_t getNBits() const {
        return nBits;
    }

    void setNBits(uint32_t nBits) {
        BlockHeader::nBits = nBits;
    }

    uint32_t getNonce() const {
        return nonce;
    }

    void setNonce(uint32_t nonce) {
        BlockHeader::nonce = nonce;
    }

};


#endif //PSYCHIC_GARBANZO_BLOCKHEADER_H
