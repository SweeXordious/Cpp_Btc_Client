//
// Created by chizisch on 2/3/20.
//

#ifndef PSYCHIC_GARBANZO_BLOCKHEADERBUILDER_H
#define PSYCHIC_GARBANZO_BLOCKHEADERBUILDER_H


#include "BlockHeader.h"
#include <array>

using namespace std;
class BlockHeaderBuilder {
private:
    int32_t version;
    array<char, HASH_ARRAY_SIZE> prev_block_header;
    array<char, HASH_ARRAY_SIZE> merkle_root;
    uint32_t time;
    uint32_t nBits;
    uint32_t nonce;
    BlockHeader blockHeader;

public:

    BlockHeader& build() {
        blockHeader = BlockHeader(version, prev_block_header, merkle_root, time, nBits, nonce);
        return blockHeader;
    }

    const BlockHeader &getBlockHeader() const {
        return blockHeader;
    }

    BlockHeaderBuilder& setVersion(int32_t version) {
        BlockHeaderBuilder::version = version;
        return *this;
    }

    BlockHeaderBuilder& setTime(uint32_t time) {
        BlockHeaderBuilder::time = time;
        return *this;
    }

    BlockHeaderBuilder& setNBits(uint32_t nBits) {
        BlockHeaderBuilder::nBits = nBits;
        return *this;
    }

    BlockHeaderBuilder& setNonce(uint32_t nonce) {
        BlockHeaderBuilder::nonce = nonce;
        return *this;
    }

    BlockHeaderBuilder& setPrevBlockHeader(array<char, HASH_ARRAY_SIZE> prevBlockHeader) {
        prev_block_header = prevBlockHeader;
        return *this;
    }

    BlockHeaderBuilder& setMerkleRoot(array<char, HASH_ARRAY_SIZE> merkleRoot) {
        merkle_root = merkleRoot;
        return *this;
    }
};


#endif //PSYCHIC_GARBANZO_BLOCKHEADERBUILDER_H
