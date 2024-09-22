#include <stdio.h>
#include <stdlib.h>

#include "ArgcCheck.h"
#include "OutputColours.h"

int check_argc(int argc)
{
    if (argc < 3) {
        fprintf(stderr, RED "Error: enter files names!\n" COLOUR_RESET);
        return -1;
    }
    return 0;
}
