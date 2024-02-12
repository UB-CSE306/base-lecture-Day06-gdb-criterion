#include <stdio.h>   // fprintf
#include <stdlib.h>  // EXIT_FAILURE, EXIT_SUCCESS
#include "code.h"    // convert, factorial


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments (%d) given to program, one expected.\n",(argc-1));
        exit(EXIT_FAILURE);
    }

    int n = convert(argv[1]);

    long unsigned fn = factorial(n);

    fprintf(stdout, "factorial(%d) is %lu\n",n,fn);
    
    return EXIT_SUCCESS;
}
