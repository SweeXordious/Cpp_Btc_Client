//
// Created by chizisch on 2/9/20.
//

#include "Script.h"

Script::Script() {
    stack = std::stack<std::string, std::deque<opcodetype>>();
}

bool Script::execute() {



    return false;
}

void Script::fillP2pkh(std::string pubKeyHash) {
    /*
    stack.push(OP_CHECKSIG);
    stack.push(OP_EQUALVERIFY);
    stack.push(pubKeyHash);
    stack.p
*/
}
