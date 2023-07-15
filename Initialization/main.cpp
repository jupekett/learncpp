#include <iostream>

// 6 ways to initialize variables
// Source: https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
int main()
{
    int a;     // default init (indetermine value)
    int b = 5; // copy init
    int c(6);  // direct init (avoid, because looks like function)

    // list initialization methods; preferred after C++11
    int d{7};    // direct list init
    int e = {8}; // copy list init
    int f{};     // value init (to 0 or empty depending on type)

    return 0;
}
