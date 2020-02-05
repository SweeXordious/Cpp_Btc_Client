//
// Created by chizisch on 2/5/20.
//


#include <include/includes.h>
#include <src/block/BlockHeaderBuilder.h>

TEST_CASE("Block Header Builder test"){
    std::array<char, HASH_ARRAY_SIZE> prevBlockHash = sha256Array("prevBlockHash");
    std::array<char, HASH_ARRAY_SIZE> merkleRoot = sha256Array("merkleRoot");

    BlockHeader expected_bh = BlockHeader(1, prevBlockHash, merkleRoot, 101010101, 2, 10);

    BlockHeaderBuilder bhb = BlockHeaderBuilder();
    bhb.setMerkleRoot(merkleRoot)
        .setNBits(2)
        .setNonce(10)
        .setPrevBlockHeader(prevBlockHash)
        .setVersion(1)
        .setTime(101010101);

    BlockHeader actual_bh = bhb.build();

    CHECK (actual_bh == expected_bh);
}