//
// Created by chizisch on 2/1/20.
//

#include "BlockHeader.h"


BlockHeader::BlockHeader(int32_t version, array<char, HASH_ARRAY_SIZE> prevBlockHeader, array<char, HASH_ARRAY_SIZE> merkleRoot, uint32_t time, uint32_t nBits,
                         uint32_t nonce) : version(version), time(time), nBits(nBits), nonce(nonce), prev_block_header(prevBlockHeader), merkle_root(merkleRoot) {

}

int32_t BlockHeader::getVersion() const {
    return version;
}

void BlockHeader::setVersion(int32_t version) {
    BlockHeader::version = version;
}

array<char, HASH_ARRAY_SIZE> BlockHeader::getPrevBlockHeader() const {
    return prev_block_header;
}

array<char, HASH_ARRAY_SIZE> BlockHeader::getMerkleRoot() const {
    return merkle_root;
}

uint32_t BlockHeader::getTime() const {
    return time;
}

void BlockHeader::setTime(uint32_t time) {
    BlockHeader::time = time;
}

uint32_t BlockHeader::getNBits() const {
    return nBits;
}

void BlockHeader::setNBits(uint32_t nBits) {
    BlockHeader::nBits = nBits;
}

uint32_t BlockHeader::getNonce() const {
    return nonce;
}

void BlockHeader::setNonce(uint32_t nonce) {
    BlockHeader::nonce = nonce;
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


