#include <iostream>

// #define LOG(x) std::cout << x << '\n';

// Question #3
// Link: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/

double askDouble()
{
    std::cout << "Enter a double value: ";
    double d{0.0};
    std::cin >> d;
    // LOG(d);
    return d;
}

char askOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char c{};
    std::cin >> c;
    // LOG(c);
    return c;
}

bool checkOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
    {
        // LOG("Operator is ok")
        return 1;
    }
    else
    {
        // LOG("Operator is wrong")
        return 0;
    }
}

double calculate(double a, double b, char _operator)
{
    double result{0.0};
    if (_operator == '+') result = a + b;
    else if (_operator == '-') result = a - b;
    else if (_operator == '*') result = a * b;
    else if (_operator == '/') result = a / b;
    return result;
}

int main()
{
    double a{askDouble()};
    double b{askDouble()};

    char op{askOperator()};
    bool opIsOk{checkOperator(op)};
    if (!opIsOk) return 0;

    double result{calculate(a, b, op)};
    std::cout << a << " " << op << " " << b << " is " << result << '\n';
    return 0;
}
