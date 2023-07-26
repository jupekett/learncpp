#include <bitset>
#include <iostream>

#define LOG(x) std::cout << x << '\n';

std::bitset<4> rotateLeft(std::bitset<4> bits)
{
    // `bits << 1` does the left shift
    // `bits >> 3` preserves the leftmost bit
    return (bits << 1) | (bits >> 3);
}

int main()
{
    LOG("===========================")
    LOG("Bitwise shift")

    std::bitset<4> x{0b1100};
    LOG(x);        // as is: 1100
    LOG((x >> 1)); // shift right by 1, yielding 0110
    LOG((x << 1)); // shift left by 1, yielding 1000

    LOG("===========================")
    LOG("Bitwise NOT")

    std::bitset<4> fourBit{0b0100};
    std::cout << fourBit << " --> " << ~fourBit << '\n';

    std::bitset<8> eightBit{0b0100};
    std::cout << eightBit << " --> " << ~eightBit << '\n';

    LOG("===========================")
    LOG("Bitwise OR")

    std::bitset<4> orA{0b0101};
    std::bitset<4> orB{0b0110};

    std::cout << orA << " | " << orB << " --> " << (orA | orB) << '\n';

    LOG("===========================")
    LOG("Bitwise AND")

    std::bitset<4> andA{0b0001};
    std::bitset<4> andB{0b0011};
    std::bitset<4> andC{0b0111};

    std::cout << andA << " & " << andB << " & " << andC << " -->" << (andA & andB & andC) << '\n';

    LOG("===========================")
    LOG("Bitwise XOR")

    std::bitset<4> xorA{0b0001};
    std::bitset<4> xorB{0b0011};
    std::bitset<4> xorC{0b0111};

    std::cout << xorA << " ^ " << xorB << " ^ " << xorC << " --> " << (xorA ^ xorB ^ xorC) << '\n';

    LOG("===========================")
    LOG("Bitwise assignment")

    std::bitset<4> bits{0b0100};
    bits >>= 1; // same works for <<=, |=, &=, ^=
    std::cout << bits << '\n';

    LOG("===========================")
    LOG("Bitwise rotate")

    std::bitset<4> rotA{0b0001};
    LOG(rotateLeft(rotA));

    std::bitset<4> rotB{0b1001};
    LOG(rotateLeft(rotB));

    std::bitset<4> xxx{0b0001};
    std::cout << (xxx << 1) << '\n';

    return 0;
}
