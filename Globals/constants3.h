#ifndef CONSTANTS3_H
#define CONSTANTS3_H

/*
Inline variables in a header file for constants.
- C++17
- all definitions of the inline variable must be identical. Otherwise --> UB.
- the inline variable definition must be present in every file that uses the variable.
- allowed in multiple files without violating the one definition rule
- inline global variables have external linkage by default
- linker will consolidate all definitions of this variable into a single definition
--> only 1 copy in entire program, even if header is included in 100 files.
*/
namespace constants3
{
    // Note: now inline constexpr
    inline constexpr double pi{3.14159};
    inline constexpr double avogadro{6.0221413e23};
    inline constexpr double gravity{9.2};
}

/*
Pros
- simple & performant

Cons
- constant value changes? --> every file with include must be recompiled
*/

#endif
