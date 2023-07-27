#include <iostream>
#include <cstring>     // for strlen
#include <string>      // for std::string
#include <limits>      // for std::numeric_limits
#include <string_view> // std::string_view is C++17

void cLiteralExample()
{
    std::cout << "=========== cLiteralExample ===============" << '\n';

    const char *s1{"hi"};
    std::cout << "Length of " << s1 << " is " << strlen(s1) << '\n'; // 2

    // size includes null terminator
    std::cout << "Size of hi is " << std::size("hi") << '\n'; // 3
}

// Parameter str makes a copy of its initializer:
// the argument given in function call.
void printString(std::string str)
{
    std::cout << str << '\n';
}

std::string createString()
{
    std::string str{"This is new string"};
    return str; // but str is destroyed at the end of function scope :(
}

void stringBasicExample()
{
    std::cout << "=========== stringBasicExample ===============" << '\n';

    // C++ string
    // It makes a copy of its initializer in memory. Both live separate lives after that.
    std::string s{"ho"};

    printString(s);

    std::cout << "Length of " << s << " is " << s.size() << '\n'; // or s2.length()
    // std::string::length() returns unsigned int --> not always good.
    // use std::ssize() instead to get signed int (C++20), or static_cast to int

    std::string s3{createString()};
}

void nullTerminatorExample()
{
    std::cout << "=========== nullTerminatorExample ===============" << '\n';

    // With a C-style array, null terminator is included as an element
    // in the character array.
    // std::size prints the size of the array, not the string represented.
    std::cout << "literal: " << std::size("Hello") << '\n';   // 6
    std::cout << "literal: " << std::size("He\0llo") << '\n'; // 7

    // std::string
    std::string s{"Hello"};
    std::cout << "std::string: " << std::size(s) << '\n'; // 5

    std::string s2{"He\0llo"};
    std::cout << "std::string: " << std::size(s2) << '\n'; // 2

    // std::string_view
    std::string_view sv2{"He\0llo"};
    std::cout << "std::string_view: " << std::size(sv2) << '\n'; // 2
}

void stringInputExample()
{
    std::cout << "=========== stringInputExample ===============" << '\n';

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
}

/*
std::string_view is a read-only string that avoids copying existing strings for
performance & memory reasons.
It is basically a read-only pointer.
Prefer it over other string types when read-only is enough.

Original string should not be modified or destroyed while the view is using it.
Otherwise you get UB (undefined behavior) due to a "dangling view"
*/
void stringViewExample()
{
    std::cout << "=========== stringViewExample ===============" << '\n';

    std::string_view sv1{"c-style literal"}; // initialize with C-style literal
    std::cout << sv1 << '\n';

    std::string s{"string"};
    std::string_view sv2{s}; // initialize with std::string
    std::cout << sv2 << '\n';

    std::string_view sv3{sv2}; // initialize with std::string_view
    std::cout << sv3 << '\n';

    // Assignment only repoints the string_view to a new string.
    // It doesn't modify the original string in any way.
    sv3 = "sv3 updated with c-literal";
    std::cout << "sv3: " << sv3 << '\n';
    std::cout << "sv2: " << sv2 << '\n';
}

/*
std::string_view works best as a read-only function parameter.
You can pass in any of these without making a copy:
- C-style string
- std::string
- std::string_view

Alternative would be:
const std::string&
, but learn more about pointers first.
*/
void printStringView(std::string_view str)
{
    std::cout << str << '\n';
}

/*
C-style literal and std::string will implicitly convert to std::string_view
*/
void stringViewImplicitExample()
{
    std::cout << "=========== stringViewImplicitExample ===============" << '\n';

    printStringView("c-literal");

    std::string str{"standard string"};
    printStringView(str);

    std::string_view strV{str};
    printStringView(strV);
}

void literalSuffixesExample()
{
    std::cout << "=========== literalSuffixesExample ===============" << '\n';

    using namespace std::string_literals;      // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix

    std::cout << "c-literal\n";             // C-style string literal
    std::cout << "string literal\n"s;       // std::string literal
    std::cout << "string_view literal\n"sv; // std::string_view literal
}

void constexprExample()
{
    std::cout << "=========== constexprExample ===============" << '\n';

    constexpr std::string_view strV{"constant string_view"}; // strV is a string symbolic constant
    std::cout << strV << '\n';                               // strV will be replaced with the constant at compile time

    // std::string got constexpr in C++20, but it has some limitations.
    // See some documentation if you want to learn.
    // constexpr std::string str{"constant string"}; // won't compile: std::string is not a literal
}

void stringViewInvalidationExample()
{
    std::cout << "=========== stringViewInvalidationExample ===============" << '\n';

    std::string s{"Original string"};
    std::string_view sv{s}; // sv is now viewing s
    std::cout << sv << '\n';

    s = "Something else entirely"; // s is modified --> invalidates sv
    std::cout << sv << '\n';       // UB

    sv = s;                  // sv is now viewing s again --> revalidated
    std::cout << sv << '\n'; // prints the expected message
}

void stringViewModifiersExample()
{
    std::cout << "=========== stringViewModifiersExample ===============" << '\n';

    std::string s{"string"};

    std::string_view sv{s};
    std::cout << sv << '\n';

    sv.remove_prefix(1);
    std::cout << sv << '\n';

    sv.remove_suffix(2);
    std::cout << sv << '\n';

    sv = s; // Reset the view
    std::cout << sv << '\n';
}

// Local std::strings are destroyed at end of function scope --> UB
std::string_view createSvUB()
{
    std::string s{"function local string"};
    return std::string_view{s};
}

// C-style literals exist for the duration of entire program --> safe
std::string_view createSvSafe()
{
    return std::string_view{"function local C-style literal"};
}

std::string_view convertToView(std::string_view sv)
{
    return sv;
}

void stringViewReturnExample()
{
    std::cout << "=========== stringViewReturnExample ===============" << '\n';

    std::string_view sv1{createSvUB()};
    std::cout << sv1 << '\n'; // UB

    std::string_view sv2{createSvSafe()};
    std::cout << sv2 << '\n'; // works as expected

    std::string s{"local string"};
    std::string_view sv3{convertToView(s)};
    std::cout << sv3 << '\n'; // works because string s is still in scope
}

int main()
{
    cLiteralExample();

    stringBasicExample();

    nullTerminatorExample();

    stringInputExample();

    stringViewExample();

    stringViewImplicitExample();

    literalSuffixesExample();

    constexprExample();

    stringViewInvalidationExample();

    stringViewModifiersExample();

    stringViewReturnExample();

    return 0;
}
