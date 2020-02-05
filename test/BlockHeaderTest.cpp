//
// Created by chizisch on 2/4/20.
//

#include "include/includes.h"

TEST_CASE("Block Header test"){
    std::array<char, HASH_ARRAY_SIZE> prevBlockHash = sha256Array("prevBlockHash");
    std::array<char, HASH_ARRAY_SIZE> merkleRoot = sha256Array("merkleRoot");

    BlockHeader bh = BlockHeader(1, prevBlockHash, merkleRoot, 101010101, 2, 10);

    CHECK(bh.getMerkleRoot() ==  sha256Array("merkleRoot"));
}