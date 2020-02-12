sudo apt-get update

# Install libgmp for multiprecision calculations
sudo apt-get install -y libgmp3-dev

# Install libsecp256k1 for ecdsa operations
sudo apt-get install -y git autoconf
git clone https://github.com/bitcoin-core/secp256k1
cd secp256k1
./autogen.sh
./configure
make
sudo make install

