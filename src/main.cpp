#include <iostream>
#include <cstdint>
#include "Rijndael.hpp"

int main() {
    Rijndael rijn = Rijndael(128, 192);
    SBox sbox = SBox();
    std::cout << std::hex << (int) sbox.get_substitute(0x5A) << std::endl;
    return 0;
}

