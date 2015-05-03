# levenshtein(3) [![Build Status](https://img.shields.io/travis/wooorm/levenshtein.c.svg?style=flat)](https://travis-ci.org/wooorm/levenshtein.c) [![Coverage Status](https://img.shields.io/coveralls/wooorm/levenshtein.c.svg?style=flat)](https://coveralls.io/r/wooorm/levenshtein.c?branch=master)

Vladimir Levenshtein’s edit distance algorithm<sup>[1](http://en.wikipedia.org/wiki/Levenshtein_distance)</sup> as a C library. There’s also a CLI: [levenshtein(1)](https://github.com/wooorm/levenshtein), and a [JavaScript version](https://github.com/wooorm/levenshtein-edit-distance).

## Installation

CLib:

```sh
$ clib install wooorm/levenshtein.c
```

Or clone the repo.

## Usage

### unsigned int levenshtein(const char *a, const char *b);

```c
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
```

## License

[MIT](LICENSE) © [Titus Wormer](http://wooorm.com)
