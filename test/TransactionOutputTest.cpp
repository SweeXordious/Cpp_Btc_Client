//
// Created by chizisch on 2/15/20.
//

#include "include/includes.h"

TEST_CASE("Transaction output tests"){

    TransactionOutput tout = TransactionOutput(100, "Pkey Script");

    CHECK(tout.getValue() == 100);

    TransactionOutput toutCopy = TransactionOutput(100, "Pkey Script");

    CHECK (tout == toutCopy);

    TransactionOutput wrongCopy = TransactionOutput(100, "Wrong output");

    CHECK (tout != wrongCopy);
}