//
// Created by chizisch on 2/1/20.
//
#include "include/includes.h"
#include <iostream>
#include <string>


TEST_CASE("MerkleTree tests: Adding function with string parameter"){

    MerkleTree m = MerkleTree();

    std::string tx1 = sha256String("tx1");
    m.addTx(tx1);

    CHECK(m.getSize() == 1);
    CHECK(m.getTxsHash()[0] == tx1);
}

TEST_CASE("MerkleTree tests: Adding function with array parameter"){

    MerkleTree m = MerkleTree();

    std::string tx1 = sha256String("tx1");
    m.addTx(stringToArray(tx1));

    CHECK(m.getSize() == 1);
    CHECK(m.getTxsHash()[0] == tx1);
}

TEST_CASE("MerkleTree tests: Adding function with an empty hash"){

    MerkleTree m = MerkleTree();

    CHECK_THROWS(m.addTx(""));
    CHECK(m.getSize() == 0);
}


TEST_CASE("MerkleTree tests: Checking the root calculation with an even number of transactions"){

    MerkleTree m = MerkleTree();

    m.addTx(sha256String("tx1"));
    m.addTx(sha256String("tx2"));
    m.addTx(sha256String("tx3"));
    m.addTx(sha256String("tx4"));

    m.calculateRoot();

    CHECK(m.getSize() == 4);
    CHECK(m.getRoot() == "8ca33c8ed532319f647dfc555654e0065c1037e0a80a9516fbbdea61ff906e09");
}

TEST_CASE("MerkleTree test: Checking the root calculation with an odd number of transactions"){

    MerkleTree m = MerkleTree();

    m.addTx(sha256String("tx1"));
    m.addTx(sha256String("tx2"));
    m.addTx(sha256String("tx3"));

    m.calculateRoot();

    CHECK(m.getSize() == 3);
    CHECK(m.getRoot() == "836357c0bdcd8a83e72ebca62b6cb8cc6747737354c1e2eaa78a3dcdb9c4918b");
    CHECK_NOTHROW(m.getRoot());
}


TEST_CASE("MerkleTree test: Checking the root Char getter"){

    MerkleTree m = MerkleTree();

    m.addTx(sha256String("tx1"));
    m.addTx(sha256String("tx2"));
    m.addTx(sha256String("tx3"));

    m.calculateRoot();

    CHECK(std::string(m.getRootChar(), HASH_ARRAY_SIZE) == "836357c0bdcd8a83e72ebca62b6cb8cc6747737354c1e2eaa78a3dcdb9c4918b");
    CHECK(m.getRootArray() == std::array<char, HASH_ARRAY_SIZE> { '8', '3', '6', '3', '5', '7', 'c', '0', 'b', 'd', 'c', 'd', '8', 'a', '8',
                                                                  '3', 'e', '7', '2', 'e', 'b', 'c', 'a', '6', '2', 'b', '6', 'c', 'b', '8',
                                                                  'c', 'c', '6', '7', '4', '7', '7', '3', '7', '3', '5', '4', 'c', '1', 'e',
                                                                  '2', 'e', 'a', 'a', '7', '8', 'a', '3', 'd', 'c', 'd', 'b', '9', 'c', '4',
                                                                  '9', '1', '8', 'b' }
                                                                  );

    CHECK_NOTHROW(m.getRoot());
}


TEST_CASE("MerkleTree test: root getters exceptions"){

    MerkleTree m = MerkleTree();

    m.addTx(sha256String("tx1"));
    m.addTx(sha256String("tx2"));
    m.addTx(sha256String("tx3"));

    CHECK_THROWS(m.getRoot());
    CHECK_THROWS(m.getRootChar());

}

TEST_CASE("MerkleTree test: calculating the root of an empty merkle tree"){

    MerkleTree m = MerkleTree();

    CHECK_THROWS(m.calculateRoot());

    CHECK_THROWS(m.getRootChar());

}



