#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "levenshtein.h"

static int assertionCount = 0;

static int errorCount = 0;

static void
assertDistance(const char *input, const char *alternative, unsigned int result) {
    unsigned int res = levenshtein(input, alternative);

    if (res != result) {
        errorCount++;

        fprintf(stderr, "\033[31m");
        fprintf(stderr,
            "  (✖) For `%s` and `%s`. Expected `%d`, got `%d`",
            input, alternative, result, res
        );
        fprintf(stderr, "\033[0m");
        fprintf(stderr, "\n");
    } else {
        printf("\033[32m.\033[0m");
    }

    assertionCount++;
}

int
main() {
    /*
     * It should work.
     */

    assertDistance("", "a", 1);
    assertDistance("a", "", 1);
    assertDistance("", "", 0);
    assertDistance("levenshtein", "levenshtein", 0);
    assertDistance("sitting", "kitten", 3);
    assertDistance("gumbo", "gambol", 2);
    assertDistance("saturday", "sunday", 3);

    /*
     * It should match case sensitive.
     */

    assertDistance("DwAyNE", "DUANE", 2);
    assertDistance("dwayne", "DuAnE", 5);

    /*
     * It not care about parameter ordering.
     */

    assertDistance("aarrgh", "aargh", 1);
    assertDistance("aargh", "aarrgh", 1);

    /*
     * Some tests form `hiddentao/fast-levenshtein`.
     */

    assertDistance("a", "b", 1);
    assertDistance("ab", "ac", 1);
    assertDistance("ac", "bc", 1);
    assertDistance("abc", "axc", 1);
    assertDistance("xabxcdxxefxgx", "1ab2cd34ef5g6", 6);
    assertDistance("xabxcdxxefxgx", "abcdefg", 6);
    assertDistance("javawasneat", "scalaisgreat", 7);
    assertDistance("example", "samples", 3);
    assertDistance("sturgeon", "urgently", 6);
    assertDistance("levenshtein", "frankenstein", 6);
    assertDistance("distance", "difference", 5);

    /*
     * Log total errors.
     */

    printf("\n");

    if (errorCount != 0) {
        printf("\033[31m");
        printf(
            "(✖) Failed on %d of %d assertions",
            errorCount, assertionCount
        );
        printf("\033[0m");
        printf("\n");

        exit(EXIT_FAILURE);
    }

    /*
     * Or, log total successes.
     */

    printf("\033[32m");
    printf("(✓) Passed %d assertions without errors", assertionCount);
    printf("\033[0m");
    printf("\n");

    return 0;
}
