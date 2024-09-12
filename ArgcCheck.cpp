#include <stdio.h>
#include <stdlib.h>

#include "ArgcCheck.h"
#include "OutputColours.h"

void check_argc(int argc)
{
    if (argc < 3) {
        fprintf(stderr, RED "Error: enter files names!\n" COLOUR_RESET);
        exit(1);
    }
}
