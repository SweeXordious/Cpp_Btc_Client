//
// Created by chizisch on 2/9/20.
//

#include "Script.h"

Script::Script() {
    script = std::vector<std::string>();
}

bool Script::execute() {

    if(stack.size() == 0) throw "Error: The stack containing the script is empty!";

    std::stack<std::string, std::deque<std::string>> execStack;

    for (auto op : script) {

        if(op == optypeToString(OP_CHECKSIG)){

        }
        else if (op == optypeToString(OP_DUP)) execStack.push(execStack.top());
        else if(op == optypeToString(OP_EQUALVERIFY)) {

        } else if (op == optypeToString(OP_CHECKSIG)){

        } else if (op == optypeToString(OP_HASH160)) {
            std::string currentOp = execStack.top();
            execStack.pop();

        }
        else execStack.push(op);


    }

    return false;
}

void Script::fillP2pkh(std::string pubKeyHash, std::string pubkey, std::string sig) {
    script.push_back(optypeToString(OP_CHECKSIG));
    script.push_back(optypeToString(OP_EQUALVERIFY));
    script.push_back(pubKeyHash);
    script.push_back(optypeToString(OP_HASH160));
    script.push_back(optypeToString(OP_DUP));
    script.push_back(pubkey);
    script.push_back(sig);
}
