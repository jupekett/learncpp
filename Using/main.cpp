#include <iostream>

namespace a
{
    int x{10};
}

namespace b
{
    int x{20};
}

int main()
{
    std::string{"asd"}; // identifier `string` is qualified by namespace std

    using std::string; // using-declaration

    string str{"standard string"}; // identifier `string` is an unqualified name
    std::cout << str << '\n';

    // a using-directive basically imports all names from the namespace into
    // current namespace without the qualifcation.
    using namespace std; // using-directive

    cout << string_view{"a string_view"} << '\n'; // can use all names from std as unqualified

    // Cons: possible naming collisions --> avoid outside of blocks
    using namespace a;
    using namespace b;
    // cout << x << '\n'; // error for ambiquous symbol

    return 0;
}
