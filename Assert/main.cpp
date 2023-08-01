#include <cassert> // for assert()
#include <cmath>   // for std::sqrt
#include <iostream>

#define NDEBUG

/*
Assertions can be used to detect programming errors.
Use them to document situations that should never happen.
They cannot be recovered from --> don't use them in place of user error handling.

Assert is a preprocessor macro.
*/
double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
    assert(gravity > 0.0 && "object won't reach the ground with negative gravity");

    if (initialHeight <= 0.0)
    {
        return 0.0;
    }
    return std::sqrt((2.0 * initialHeight) / gravity);
}

/*
Another use case: mark unimplemented functionality.
*/
void somethingUnimplemented()
{
    bool moved{false};
    assert(moved && "Need to handle case where student was moved to another class");
}

/*
static_assert is only checked at compile-time.
- a keyword instead of a precompiler macro --> no need for #include.
- evaluated by compiler --> condition must be a constant expression
- not compiled out of release builds
*/
void compileTimeCheck()
{
    static_assert(sizeof(long) == 8, "long must be 8 bytes");
    static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");
}

int main()
{
    std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

    somethingUnimplemented();

    compileTimeCheck();

    return 0;
}
