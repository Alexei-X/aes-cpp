#include <array>
#include <iostream>
#include <cstdint>
#include "SBox.hpp"

using State = std::array<std::array<uint8_t, 4>, 4>;

class Rijndael {
private:
    int block_size, key_size;
    State state;
    SBox sbox;

    void swap(std::array<uint8_t, 4> *arr_p, int i1, int i2) {
        uint8_t temp = (*arr_p)[i1];
        (*arr_p)[i1] = (*arr_p)[i2];
        (*arr_p)[i2] = temp;
    }

    void shift(std::array<uint8_t, 4> arr, int shift_value) {
        for (int it = 0; it < shift_value; it++) {
            swap(&arr, 0, 1);
            swap(&arr, 1, 2);
            swap(&arr, 2, 3);
            swap(&arr, 3, 4);
        }
    }

public:
    Rijndael(int block_size, int key_size) : block_size(block_size), key_size(key_size) {
        if (block_size % 32 != 0 || key_size % 32 != 0) {
            block_size = 128;
            key_size = 128;
        }
        this->sbox = SBox();
    }

    void SubBytesStep() {
        for (int line = 0; line < 4; line++) {
            for (int column = 0; column < 4; column++) {
                this->state[line][column] = this->sbox.get_substitute(this->state[line][column]);
            }
        }
    }

    void ShiftRowsStep() {
        for (int i = 1; i < 4; i++)
            shift(this->state[i], i);
    }

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
