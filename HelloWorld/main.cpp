#include <iostream>
#include <vector>
#include <string>

using namespace std;

void simpleHello()
{
    cout << "Moro maailma" << endl;
}

void complexHello()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code"};
    for (const string &word : msg)
    {
        cout << word << " ";
    };
    cout << endl;
}

int main()
{
    simpleHello();
    complexHello();
}
