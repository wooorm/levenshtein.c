/**
 * `levenshtein.h` - levenshtein
 *
 * MIT licensed.
 *
 * Copyright (c) 2015 Titus Wormer <tituswormer@gmail.com>
 */

/**
 * Returns an unsigned integer, depicting
 * the difference between `a` and `b`.
 *
 * See http://en.wikipedia.org/wiki/Levenshtein_distance
 * for more information.
 */

unsigned int
levenshtein(const char *a, const char *b);
