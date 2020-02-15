//
// Created by chizisch on 2/15/20.
//

#include "include/includes.h"

TEST_CASE("Transaction input builder tests"){

    TxInputBuilder tb = TxInputBuilder();
    tb.setHashKey("HashKey")
        .setIndex(2)
        .setSequenceNumber(3)
        .setSignature("Signature")
        .setSigScript("Signature script");

    TransactionInput txin = tb.build();
    TransactionInput txout = TransactionInput("HashKey",2 ,"Signature script", "Signature", 3);

    CHECK(txin == txout);
}