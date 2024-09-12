#include "Globals.h"
#include "Sorting.h"
#include "ScanPrint.h"
#include "ArgcCheck.h"

int main(int argc, const char* argv[])
{
    check_argc(argc);

    char text[nlines][line_len] = {};
    scan_text(text, argv[1]);

    int inds[nlines] = {};
    fill(inds);

    sort_text(text, inds);

    printf_text(text, inds, argv[2]);
    //print_text(text, inds);

    return 0;
}
