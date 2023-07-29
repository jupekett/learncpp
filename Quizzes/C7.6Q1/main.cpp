#include <iostream>

// A calculator with switch-case.

int askInteger()
{
    std::cout << "Enter an integer: ";
    int x{0};
    std::cin >> x;
    return x;
}

char askOperator()
{
    std::cout << "Enter an operator (+, -, *, /, or %): ";
    char op{};
    std::cin >> op;
    return op;
}

int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            std::cout << "Division by zero, defaulting to 0\n";
            break;
        }
        else
            return a / b;
    case '%':
        return a % b;
    default:
        std::cout << "calculate(): Operator not supported\n";
        return 0;
    }
}

int main()
{
    int a{askInteger()};
    int b{askInteger()};
    char op{askOperator()};

    int result{calculate(a, b, op)};
    std::cout << a << ' ' << op << ' ' << b << " is " << result << '\n';
}
