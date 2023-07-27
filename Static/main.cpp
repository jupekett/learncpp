#include <iostream>

/*
static local variables
    - `static` keyword
    - gives the variable static duration
    -->  created at program start, destroyed at program end (just like global variable)
    - only initialized the first time the code is executed

Pros:
- longer duration than regular local variables
- visibility limited to local scope

Best practice:
- avoid unless the variable value never needs to be reset.
*/

void cannotIncrementAndPrint()
{
    int value{1};
    ++value;
    std::cout << "local variable incremented: " << value << '\n';
}

void incrementAndPrint()
{
    // use `s_` prefix to denote static local variables
    static int s_value{1};
    ++s_value;
    std::cout << "static local variable incremented: " << s_value << '\n';
}

// Example of common usage for static local variables: ID generation.
// - avoids duplicate values during program runtime
int generateID()
{
    static int s_itemID{0};
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

// static local constants
// - use when you need constant value for something expensive
const int *createExpensiveObject()
{
    // ... please substitute with a better example when you learn
    static const int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    return array;
}

int main()
{
    cannotIncrementAndPrint();
    cannotIncrementAndPrint();
    cannotIncrementAndPrint();

    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    int monster_1_id{generateID()};
    int monster_2_id{generateID()};
    int monster_3_id{generateID()};

    std::cout << "monster 1 ID: " << monster_1_id << '\n';
    std::cout << "monster 2 ID: " << monster_2_id << '\n';
    std::cout << "monster 3 ID: " << monster_3_id << '\n';
}
