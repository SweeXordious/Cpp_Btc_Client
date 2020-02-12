//
// Created by chizisch on 2/11/20.
//

#include "include/includes.h"

TEST_CASE("Testing with a stcript") {

    Script s = Script("hehehheheh");
    s.fillP2pkh(ripemd160String(sha256String("033e8c5dcb8e35670de496b57c1fa4366800ce3be5fded9b8800759881bc8da2e5")), "033e8c5dcb8e35670de496b57c1fa4366800ce3be5fded9b8800759881bc8da2e5", "304502203f004eeed0cef2715643e2f25a27a28f3c578e94c7f0f6a4df104e7d163f7f8f022100b8b248c1cfd8f77a0365107a9511d759b7544d979dd152a955c867afac0ef78601");
    //60d47ac02b129c08f94232ea506d1826424fe7be
    //CHECK (s.execute() == true);
}