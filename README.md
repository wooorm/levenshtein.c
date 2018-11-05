# levenshtein(3) [![Build Status][travis-badge]][travis-status] [![Coverage Status][coverage-badge]][coverage-status]

Vladimir Levenshtein’s edit distance algorithm<sup>[1][wiki]</sup> as a C library. There’s also a CLI: [levenshtein(1)][cli], and a [JavaScript version][js].

## Installation

CLib:

```sh
$ clib install wooorm/levenshtein.c
```

Or clone the repo.

## Usage

### `unsigned int levenshtein(const char *a, const char *b);`

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

[MIT][] © [Titus Wormer][author]

[travis-badge]: https://img.shields.io/travis/wooorm/levenshtein.c.svg

[travis-status]: https://travis-ci.org/wooorm/levenshtein.c

[coverage-badge]: https://img.shields.io/coveralls/wooorm/levenshtein.c.svg

[coverage-status]: https://coveralls.io/r/wooorm/levenshtein.c?branch=master

[wiki]: http://en.wikipedia.org/wiki/Levenshtein_distance

[cli]: https://github.com/wooorm/levenshtein

[js]: https://github.com/words/levenshtein-edit-distance

[mit]: LICENSE

[author]: http://wooorm.com
