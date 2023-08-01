#include <iostream>
#include <limits>

// Completely empties std::cin buffer, e.g. in case of failed extraction.
void ignoreLine()
{
    // "please ignore all characters in buffer,
    // and also the terminating newline"
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while (true)
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        if (!std::cin) // if previous extraction failed
        {
            if (std::cin.eof()) // if the stream was closed, e.g. via Ctrl+D on Unix system.
            {
                exit(0); // shut down the program
            }
            std::cin.clear(); // put us back in "normal" operation mode after cin failure mode
            ignoreLine();     // ... and remove the bad input
            std::cout << "Oops, that input is invalid. Please try again.\n";
        }
        else
        {
            ignoreLine(); // remove all extra input left in buffer after reading
            return x;
        }
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op{};
        std::cin >> op;

        if (!std::cin) // if previous extraction failed
        {
            if (std::cin.eof()) // if the stream was closed, e.g. via Ctrl+D on Unix system.
            {
                exit(0); // shut down the program
            }
            std::cin.clear(); // put us back in "normal" operation mode after cin failure mode
        }
        ignoreLine(); // remove all extra input left in buffer after reading

        switch (op)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return op;
        default:
            std::cout << "Oops, that input is invalid. Please try again.\n";
        }
    }
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default:
        // don't trust the user to give correct input every time
        std::cout << "Something went wrong: printResult got an invalid operator.\n";
    }
}

int main()
{
    double x{getDouble()};
    char operation{getOperator()};
    double y{getDouble()};

    printResult(x, operation, y);

    return 0;
}
