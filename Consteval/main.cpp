#include <iostream>

// C++20
// `consteval` forces a function to execute at compile-time instead of runtime
// --> performance increase
// Also called "immediate functions"
consteval int greaterConsteval(int x, int y)
{
    return (x > y ? x : y);
}

// This wrapper function uses an abbreviated function template and `auto` return
// type to allow any type.
consteval auto compileTime(auto value)
{
    return value;
}

// A regular constexpr function, to be wrapped with above function.
constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    std::cout << greaterConsteval(5, 6) << '\n'; // will execute at compile time

    std::cout << greater(5, 6) << '\n';              // might not execute at compiletime, because cout doesn't require constexpr
    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile time

    int x{5};                           // not constexpr
    std::cout << greater(x, 6) << '\n'; // constexpr function can still be called at runtime

    return 0;
}
