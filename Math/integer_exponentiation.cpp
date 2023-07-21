// #include "integer_exponentiation.h"

#include <cassert> // for assert
#include <cstdint> // for std::int64_t
#include <iostream>
#include <limits> // for std::numeric_limits

// Note: exp must be non-negative
// Note: does not perform range/overflow checking, use with caution
// Note: usually WILL OVERFLOW the integer type!
constexpr std::int64_t powint(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint: exp parameter has negative value");

    // handle the 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result{1};
    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
            result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

// A safer but slower version of powint() that checks for overflow.
// Note: exp must still be non-negative.
// Returns std::numeric_limits<std::int64_t>::max() if overflow occurs.
constexpr std::int64_t powint_safe(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");

    // handle the 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result{1};

    // To make the range checks easier, we'll ensure base is positive.
    // We'll flip the result at the end if needed
    bool negativeResult{false};

    if (base < 0)
    {
        base = -base;
        negativeResult = (exp & 1);
    }

    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
        {
            // Check if result will overflow when multiplied by base
            if (result > std::numeric_limits<std::int64_t>::max() / base)
            {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }

            result *= base;
        }

        exp /= 2;

        if (exp <= 0)
            break;

        // The following needs to only execute if were' going to iterate again.

        // Check if base will overflow when multiplied by base
        if (base > std::numeric_limits<std::int64_t>::max() / base)
        {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    if (negativeResult)
        return -result;

    return result;
}

int main()
{
    std::cout << powint(7, 12) << '\n'; // 7 to the 12th power
    std::cout << powint_safe(7, 12) << '\n';
    std::cout << powint_safe(7, 23) << '\n'; // result overflows

    return 0;
}
