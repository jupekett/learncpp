#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Give an integer to add: ";
    int number{};
    std::cin >> number;
    return number;
}

void writeAnswer(int answer)
{
    std::cout << "Answer is " << answer << '\n';
}
