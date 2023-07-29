#include "add.h" // for BasicMatch::add()

#include <iostream>

namespace Foo
{
    int calculateSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Bar
{
    int calculateSomething(int x, int y)
    {
        return x - y;
    }

}

void print()
{
    std::cout << "Hi from global namespace\n";
}

namespace Bar
{
    // you can declare namespace blocks in multiple locations.
    // all declarations like this are considered part of that namespace.
    void print()
    {
        std::cout << "Hello from Bar namespace\n";
    }

    namespace Baz
    {
        // a nested namespace
        void print()
        {
            std::cout << "Hello from nested namespace Bar::Baz\n";
        }
    }
}

// nested namespace the C++17 way
namespace Foo::Goo
{
    void print()
    {
        std::cout << "Hello from nested namespace Foo::Goo\n";
    }
}

/*
Unnamed namespace
- all identifiers inside are part of parent namespace
- all identifiers inside are treated as if they have internal linkage
--> cannot be seen outside of this file
--> good if have lots of identifiers and don't want to modify each for internal linkage
*/
namespace
{
    // this function can only be accessed in this file.
    // --> same as declaring a function as `static`
    void doSomething()
    {
        std::cout << "Hi from unnamed namespace\n";
    }
}

/*
Inline namespaces
- all identifiers inside are part of parent namespace (just like unnamed namespace)
- doesn't affect linkage (unlike unnamed namespace)
--> often used for versioning of content, see main function.
*/
inline namespace V1
{
    void printSomething() // this is the "default" version of printSomething due to inline
    {
        std::cout << "V1\n";
    }
}

namespace V2
{
    void printSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
{
    std::cout << "===== multiple namespaces ======\n";
    std::cout << Foo::calculateSomething(4, 3) << '\n';
    std::cout << Bar::calculateSomething(4, 3) << '\n';

    std::cout << "===== global vs your namespace ======\n";
    print();
    ::print();
    Bar::print();

    std::cout << "===== namespace from external file ======\n";
    std::cout << BasicMath::add(4, 3) << '\n';

    std::cout << "===== nested namespaces ======\n";
    Bar::Baz::print();
    Foo::Goo::print();

    std::cout << "===== namespace alias ======\n";
    namespace Shorter = Foo::Goo;
    Shorter::print();

    std::cout << "===== unnamed namespace ======\n";
    V1::printSomething(); // calls the V1 version
    V2::printSomething(); // calls the V2 version
    printSomething();     // calls the inline version (which is V1)
    // --> preserves functionality of existing programs, while allowing V2 when you want

    return 0;
}
