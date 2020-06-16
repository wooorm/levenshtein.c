# levenshtein(3)

[![Build][build-badge]][build]
[![Coverage][coverage-badge]][coverage]

Vladimir Levenshtein’s edit distance algorithm<sup>[1][wiki]</sup> as a C library. There’s also a CLI: [levenshtein(1)][cli], and a [JavaScript version][js].

## Installation

CLib:

```sh
$ clib install wooorm/levenshtein.c
```

Or clone the repo.

## Usage

### `size_t levenshtein(const char *a, const char *b);`

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

  printf("%zu\n", levenshtein(a, b));
}
```

### `size_t levenshtein_n(const char *a, const size_t length, const char *b, const size_t bLength);`

``` c
#include <stdio.h>
#include "levenshtein.h"

int
main() {
  const char *a = "foobar";
  const char *b = "hello";

  printf("%zu\n", levenshtein_n(a, 6, b, 5));
}
```

## License

[MIT][] © [Titus Wormer][author]

[build-badge]: https://img.shields.io/travis/wooorm/levenshtein.c.svg

[build]: https://travis-ci.org/wooorm/levenshtein.c

[coverage-badge]: https://img.shields.io/coveralls/wooorm/levenshtein.c.svg

[coverage]: https://coveralls.io/github/wooorm/levenshtein.c

[wiki]: https://en.wikipedia.org/wiki/Levenshtein_distance

[cli]: https://github.com/wooorm/levenshtein

[js]: https://github.com/words/levenshtein-edit-distance

[mit]: license

[author]: https://wooorm.com
