#include "so_long.h"

void error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}