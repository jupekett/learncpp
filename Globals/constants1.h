#ifndef CONSTANTS1_H
#define CONSTANTS1_H

// Define your own namespace to hold constants.
// Before C++17, this was quite common due to simplicity.
// You have C++17 or newer? Use inline variables as in `constants3.h`
namespace constants1
{
    // inside a namespace, `g_` prefix is optional, because
    // all names defined inside a namespace are globally accessible
    // --> we know it's a global when we see a namespaced name
    constexpr double pi{3.14159};
    constexpr double avogadro{6.0221413e23};
    constexpr double gravity{9.2};
}

/*
Pros:
- defined in 1 place only --> easy to read and modify
- easy to use: just include the header file where you need the constants

Cons:
- variables copied every time the header file is included: 20 includes --> 20 copies.
- changing a value requires recompiling every file that includes this file
- large and complex constants cannot be "optimized away" --> memory-intensive
    especially due to multiple copies
    - See `constants2.cpp` how to remove this need for recompilation for offending constants.
*/

#endif
