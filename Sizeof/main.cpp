#include <iostream>

// Memory footprints of some fundamental data types will vary between machines.
// This shows what they are on your current machine.
// C++ only guarantees a minimum size (for all or only for some?)
int main()
{
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
    std::cout << '\n';

    // least integers
    std::cout << "least 8:\t" << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16:\t" << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32:\t" << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';

    // fast integers
    std::cout << "fast 8:\t\t" << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16:\t" << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32:\t" << sizeof(std::int_fast32_t) * 8 << " bits\n";
    std::cout << '\n';

    // size_t
    std::cout << "size_t:\t\t" << sizeof(std::size_t) * 8 << " bits\n";

    return 0;
}
