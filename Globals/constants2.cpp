#include "constants2.h"

// This is how you can remove the need to recompile every file which #includes
// our constants.
// C++ older than C++17 and don't have trouble with recompile times? Prefer `constants1.h`
// C++17 or newer? Prefer `constants3.h`
namespace constants2
{
    extern const double pi{3.14159};
    extern const double avogadro{6.0221413e23};
    extern const double gravity{9.2};
}

/*
Pros
- constants will be instantiated only once instead of in each code file with
    #include.
- all uses of these constants will be linked to the version instantiated here.
--> only this file needs compiling when a constant changes.

Cons
- in other files, these are treated as _runtime_ constant values, not compile-time constants
    --> can't be used anywhere that requires a compile-time constant.
    - also, runtime constants might be less optimized by compiler. 
*/
