#include <iostream>
#include <string>

// #define LOG(x) std::cout << x << std::endl;

std::string askFullName()
{
    std::cout << "Your full name, please: ";
    std::string fullName{};
    std::getline(std::cin >> std::ws, fullName);
    // LOG(fullName);
    return fullName;
}


int askAge()
{
    std::cout << "Your age, please: ";
    int age{};
    std::cin >> age;
    // LOG(age)
    return age;
}

int calculateSum(std::string name, int age)
{
    long letters{std::ssize(name)};
    return age + letters;
}


int main()
{
    // Ask full name
    const std::string fullName{askFullName()};

    // Ask age
    const int age{askAge()};

    // Tell sum of age and length of name
    const int sum{calculateSum(fullName, age)};
    std::cout << "Your age + length of name is: " << sum << '\n';
}
