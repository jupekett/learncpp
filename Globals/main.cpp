// Encapsulation is good for global constants
#include "constants1.h"
#include "constants2.h"
#include "constants3.h"

#include <iostream>

// Prefer "g" or "g_" prefix for global variables to signify scope duration.
int g_x{}; // non-initialized global variable g_x, init to zero

// Internal Linkage: `static` keyword
// ... means that variables with the keyword are not visible outside this file
// --> better than externally visible.

static int g_y;     // non-initialized internal global variable, init to zero
static int g_yy{1}; // initialized internal global variable

const int g_z{2};      // initialized internal global const variable
constexpr int g_zz{3}; // initialized internal global constexpr variable

static void foo(){}; // internal function

// External Linkage: `extern` keyword.
// ... means that external variables are visible from other files too.
// They still require forward declarations.
// See `external_linkage.cpp`
void sayHi();
extern int g_x_ext;
extern const int g_y_ext;

int main()
{
    std::cout << "===== internal linkage ======\n";
    std::cout << g_x << '\n';
    std::cout << g_y << '\n';
    std::cout << g_yy << '\n';
    std::cout << g_z << '\n';
    std::cout << g_zz << '\n';

    std::cout << "===== external linkage ======\n";
    sayHi();
    std::cout << g_x_ext << '\n';
    std::cout << g_y_ext << '\n';

    // encapsulation with namespace in separate file
    std::cout << "===== constants1.h ======\n";
    std::cout << constants1::pi << '\n';
    std::cout << constants1::avogadro << '\n';
    std::cout << constants1::gravity << '\n';

    std::cout << "===== constants2.h ======\n";
    std::cout << constants2::pi << '\n';
    std::cout << constants2::avogadro << '\n';
    std::cout << constants2::gravity << '\n';

    std::cout << "===== constants3.h ======\n";
    std::cout << constants3::pi << '\n';
    std::cout << constants3::avogadro << '\n';
    std::cout << constants3::gravity << '\n';

    return 0;
}
// these globals go out of scope here at end of file
