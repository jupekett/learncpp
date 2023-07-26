#include "add.h" // for BasicMatch::add()

#include <iostream>

namespace Foo
{
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Bar
{
    int doSomething(int x, int y)
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

int main()
{
    // multiple namespaces
    std::cout << Foo::doSomething(4, 3) << '\n';
    std::cout << Bar::doSomething(4, 3) << '\n';

    // global vs your namespace
    print();
    ::print();
    Bar::print();

    // namespace from external file
    std::cout << BasicMath::add(4, 3) << '\n';

    // nested namespaces
    Bar::Baz::print();
    Foo::Goo::print();

    // namespace alias
    namespace Shorter = Foo::Goo;
    Shorter::print();

    return 0;
}
