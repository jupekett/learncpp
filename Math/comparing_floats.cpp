#include <iostream>
#include <cmath>     // for std::abs
#include <algorithm> // for std::max

#define LOG(x) std::cout << x << '\n';

// Return true if difference between a and b is within epsilon percent of
// the larger of a and b.
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// Return true if the difference between a and be is less than absEpsilon,
// or within relEpsilon percent of the larger of a and b.
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // check if the numbers are really close.
    // needed when comparing numbers near zero
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

int main()
{
    // a is really close to 1.0, but has rounding errors.
    constexpr double a{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1};

    constexpr double relEps{1e-8};
    constexpr double absEps{1e-12};

    LOG(approximatelyEqualRel(a, 1.0, relEps));                 // compare "almost 1.0" to 1.0
    LOG(approximatelyEqualRel(a - 1.0, 0.0, relEps));           // compare "almost 0.0" to 0.0

    LOG(approximatelyEqualAbsRel(a, 1.0, absEps, relEps));      // compare "almost 1.0" to 1.0
    LOG(approximatelyEqualAbsRel(a - 1.0, 0.0, absEps, relEps)) // compare "almost 0.0" to 0.0
}
