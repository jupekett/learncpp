#include <iostream>
#include <cstring> // for strlen
#include <string>  // for std::string
#include <limits> // for std::numeric_limits

int main()
{
    // C-style string literal
    const char *s1 = "hello";
    std::cout << "Length of " << s1 << " is " << strlen(s1) << '\n';

    // C++ string
    std::string s2 = "world";
    std::cout << "Length of " << s2 << " is " << s2.size() << '\n'; // or s2.length()
    // std::string::length() returns unsigned int --> not always good.
    // use std::ssize() instead to get signed int (C++20), or static_cast to int

    // std::cin doesn't work nicely with whitespace, because splits at those
    std::cout << "Please write something here with spaces: ";
    std::string s3{};
    std::cin >> s3;
    std::cout << "You wrote: " << s3 << '\n';
    std::cout << "Rest would be given to next input read operation, and skip user input then :(" << '\n';

    // clear cin buffer of the leftovers
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // use std::getline() instead to handle whitespace properly
    std::cout << "Please repeat the same you tried previously: ";
    std::string s4{};
    std::getline(std::cin >> std::ws, s4); 
    // std::getline doesn't ignore leading whitespace automatically.
    // std::ws is input manipulator to fix that.
    std::cout << "You wrote: " << s4 << '\n';

    return 0;
}
