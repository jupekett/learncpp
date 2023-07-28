#include <iostream>

/*
For small functions, the overhead of the function call can cost more resources
than executing the function code itself:
- store the address of current instruction CPU is executing
- store register values to be restored upon returning
- instantiate and initialize parameters
- jump the execution path to the code in the function
- execute function
- jump back to the location of function call
- copy return value for output
- restore register values
- ... possible others.

Inline functions remove the cost of function call overhead, instead inlining
the function code at place of function call.

Cons:
- modern compiler knows better! might even ignore your inlining request.
- if large function, the expanded code might bloat the executable, and/or
    entirely miss out on the performance improvement.
*/
inline int min(int x, int y) // hint to compiler to inline expand this function
{
    return (x < y) ? x : y;
}

int main()
{
    std::cout << min(1,2) << '\n';
    std::cout << min(3,2) << '\n';
}
