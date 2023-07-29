#include "io.h"

/*
 * Adds two user-given integers together.
 * Structured to use a header file.
*/
int main()
{
    int x{readNumber()};
    int y{readNumber()};

    writeAnswer(x + y);

    return 0;
}
