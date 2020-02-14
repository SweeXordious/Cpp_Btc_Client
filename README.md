# psychic-garbanzo
[![Build Status](https://travis-ci.com/SweeXordious/psychic-garbanzo.svg?token=z2HQYuqNJFYxRTjxCmyT&branch=master)](https://travis-ci.com/SweeXordious/psychic-garbanzo) [![codecov](https://codecov.io/gh/SweeXordious/psychic-garbanzo/branch/master/graph/badge.svg?token=9ydUg96zDn)](https://codecov.io/gh/SweeXordious/psychic-garbanzo)



### Build 
`git clone https://github.com/SweeXordious/psychic-garbanzo`

`cd psychic-garbanzo`

`sudo bash reqs.sh`

`mkdir build`

`cd build`

`cmake ..`

`make`

`./psychic-garbanzo`

#### Build tests
`git clone https://github.com/SweeXordious/psychic-garbanzo`

`mkdir build`

`cd build`

`cmake  -DCMAKE_BUILD_TYPE=Coverage -DBUILD_TESTS=ON ..`

`make psychic-test`

`./psychic-test`

# Progress

Components:
- Hash function: sha256 => done
- Scripting language: Done 
    - still requires testing with correct signatures
    - memory leaks in the execution method that make the coverage fail
- Underlying network
    - rpc
    - p2p
    - discovery
- Script: Now
- Blocks
    - Definition
        - Header: Done
    - validation
- Transaction definition
    - addresses
    - format: json
- Merkle tree: Done
- Proof of work
- Storage
    - serialization
    - think of a db ? or just files
- ui ?
- different bases

Problems:
- When passing public keys or idk to sha256 or ripemd160, it gives wrong results from time to time. That is due to the 
fact that data is passed as ascii, hex, binary or whatever and that causes confusion.. 
