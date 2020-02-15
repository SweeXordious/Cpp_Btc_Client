//
// Created by chizisch on 2/15/20.
//

#include "include/includes.h"

TEST_CASE("Transaction Input Test"){

    TransactionInput txin = TransactionInput("hashKey", 1, "script", "signature", 2);
    CHECK(txin.getHashKey() == "hashKey");

    TransactionInput txinCopy = TransactionInput("hashKey", 1, "script", "signature", 2);
    CHECK(txin == txinCopy);

}