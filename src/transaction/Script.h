//
// Created by chizisch on 2/9/20.
//

#ifndef PSYCHIC_GARBANZO_SCRIPT_H
#define PSYCHIC_GARBANZO_SCRIPT_H

#include "include/includes.h"
#include <stack>

class Script {
private:
    std::vector<std::string> script;
    std::string tx;
public:
    Script(std::string tx);
    // The pubkeyhash should be in hexadecimal format
    void fillP2pkh(std::string pubKeyHash, std::string pubkey, std::string sig);
    bool execute();


};


#endif //PSYCHIC_GARBANZO_SCRIPT_H
