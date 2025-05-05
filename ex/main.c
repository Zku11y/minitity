#include "head.h"

int main(int ac, char **av)
{
    if (start(&av[1]))
        return 1;
    return 0;
}
