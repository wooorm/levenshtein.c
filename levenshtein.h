#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

/* `levenshtein.h` - levenshtein
 * MIT licensed.
 * Copyright (c) 2015 Titus Wormer <tituswormer@gmail.com> */

/* Returns an unsigned integer, depicting
 * the difference between `a` and `b`.
 * See http://en.wikipedia.org/wiki/Levenshtein_distance
 * for more information.
 */
#ifdef __cplusplus
extern "C" {
#endif
  
unsigned int
levenshtein(const char *a, const char *b);

#ifdef __cplusplus
}
#endif

#endif // LEVENSHTEIN_H
