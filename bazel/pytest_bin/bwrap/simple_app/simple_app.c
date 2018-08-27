#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("%s", getenv("HOSTNAME"));
    return 0;
}
