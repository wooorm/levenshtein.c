#include <stdio.h>
#include "levenshtein.h"

int
main(int argc, char **argv) {
    char *a = argv[1];
    char *b = argv[2];

    if (argc < 3) {
        fprintf(stderr, "\033[31mLevenshtein expects two arguments\033[0m\n");

        return 1;
    }

    printf("%d\n", levenshtein(a, b));
}
