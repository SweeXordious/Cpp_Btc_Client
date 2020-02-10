//
// Created by chizisch on 2/9/20.
//

#ifndef PSYCHIC_GARBANZO_SCRIPT_H
#define PSYCHIC_GARBANZO_SCRIPT_H

#include "include/includes.h"
#include <stack>

class Script {
private:
    std::stack<std::string, std::deque<opcodetype>> stack;

public:
    Script();
    void fillP2pkh(std::string pubKeyHash);
    bool execute();


};


#endif //PSYCHIC_GARBANZO_SCRIPT_H
