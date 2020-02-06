//
// Created by chizisch on 2/1/20.
//

#include "BlockHeader.h"


BlockHeader::BlockHeader(int32_t version, array<char, HASH_ARRAY_SIZE> prevBlockHeader, array<char, HASH_ARRAY_SIZE> merkleRoot, uint32_t time, uint32_t nBits,
                         uint32_t nonce) : version(version), time(time), nBits(nBits), nonce(nonce), prev_block_header(prevBlockHeader), merkle_root(merkleRoot) {

}

bool BlockHeader::operator==(const BlockHeader &rhs) const {
    return version == rhs.version &&
           prev_block_header == rhs.prev_block_header &&
           merkle_root == rhs.merkle_root &&
           time == rhs.time &&
           nBits == rhs.nBits &&
           nonce == rhs.nonce;
}

bool BlockHeader::operator!=(const BlockHeader &rhs) const {
    return !(rhs == *this);
}


