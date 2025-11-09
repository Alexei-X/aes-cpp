#include <array>

using State = std::array<std::array<char, 4>, 4>;

class Rijndael {
private:
    int block_size;
    State state;
public:
    Rijndael(int block_size) : block_size(block_size) {};
    void SubBytesStep() {}
    void ShiftRowsStep() {}
    void MixColumnsStep() {}
    void AddRoundKeyStep() {}
};
