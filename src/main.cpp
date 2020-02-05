#include <iostream>

#include "include/includes.h"
using namespace std;

int main(int argc, char* const argv[]) {

    std::cout << "Hello, World!" << std::endl;

    MerkleTree m = MerkleTree();

    m.addTx(sha256String("tx1"));
    m.addTx(sha256String("tx2"));
    m.addTx(sha256String("tx3"));

    m.calculateRoot();

    cout << m.getRoot() << endl;
    cout << m.getRoot().size() << endl;
    cout << sizeof(m.getRoot()) << endl;
    return 0;
}
