/* `levenshtein.c` - levenshtein
 * MIT licensed.
 * Copyright (c) 2015 Titus Wormer <tituswormer@gmail.com> */

#include <string.h>
#include <stdlib.h>

/* Returns an unsigned integer, depicting
 * the difference between `a` and `b`.
 * See http://en.wikipedia.org/wiki/Levenshtein_distance
 * for more information. */

unsigned int
levenshtein_n(const char *a, const unsigned int length, const char *b, const unsigned int bLength) {
  unsigned int *cache = calloc(length, sizeof(unsigned int));
  unsigned int index = 0;
  unsigned int bIndex = 0;
  unsigned int distance;
  unsigned int bDistance;
  unsigned int result;
  char code;

  /* Shortcut optimizations / degenerate cases. */
  if (a == b) {
    return 0;
  }

  if (length == 0) {
    return bLength;
  }

  if (bLength == 0) {
    return length;
  }

  /* initialize the vector. */
  while (index < length) {
    cache[index] = index + 1;
    index++;
  }

  /* Loop. */
  while (bIndex < bLength) {
    code = b[bIndex];
    result = distance = bIndex++;
    index = 0xffffffff;

    while (++index < length) {
      bDistance = code == a[index] ? distance : distance + 1;
      distance = cache[index];

      cache[index] = result = distance > result
        ? bDistance > result
          ? result + 1
          : bDistance
        : bDistance > distance
          ? distance + 1
          : bDistance;
    }
  }

  free(cache);

  return result;
}

unsigned int
levenshtein(const char *a, const char *b) {
  const unsigned int length = (unsigned int) strlen(a);
  const unsigned int bLength = (unsigned int) strlen(b);

  return levenshtein_n(a, length, b, bLength);
}
