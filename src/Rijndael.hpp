#include <array>
#include <iostream>
#include <cstdint>
#include "SBox.hpp"

using State = std::array<std::array<uint8_t, 4>, 4>;

class Rijndael {
private:
    int block_size;
    State state;
    SBox sbox;
public:
    Rijndael(int block_size) : block_size(block_size) {
        this->sbox = SBox();
    };
    void SubBytesStep() {
        for (int line = 0; line < 4; line++) {
            for (int column = 0; column < 4; column++) {
                this->state[line][column] = this->sbox.get_substitute(this->state[line][column]);
            }
        }
    }
    void ShiftRowsStep() {}
    void MixColumnsStep() {}
    void AddRoundKeyStep() {}
    void printState() {
        for (int line = 0; line < 4; line++) {
            for (int column = 0; column < 4; column++) {
                std::cout << std::hex << (int) this->state[line][column] << " ";
            }
            std::cout << std::endl;
        }
    }
};
