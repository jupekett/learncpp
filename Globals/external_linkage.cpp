#include <iostream>

int g_x_ext{11}; // non-constant globals are external by default

extern const int g_y_ext{22}; // const globals can be defined as extern

// constexpr globals can be defined as extern, but this is useless,
// because compiler must now the value at compile time,
// but compiler only reads 1 file at time
// --> compiler error in the file with forward declaration.
extern constexpr int g_z_ext{33};

// functions have external linkage by default
void sayHi()
{
    std::cout << "Hi from external_linkage.cpp!\n";
}
