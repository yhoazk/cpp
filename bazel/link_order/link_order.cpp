/*
This is a demostrator of how names in linker do not collide
as thez normally collide at compile time.
Then is possible to have multiple definitions of a type or fnc
in libraries, the linker will take only the first one and forget
about that type
https://stackoverflow.com/questions/12573816/what-is-an-undefined-reference-unresolved-external-symbol-error-and-how-do-i-fix/24675715#24675715
*/
#include "foo.h"
int main() {
    if (bar() > 2.0f) {
        return 0;
    } else {
        return 1;
    }
}