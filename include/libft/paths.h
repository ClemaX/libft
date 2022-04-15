#pragma once

#include <limits.h>
#include <stddef.h>

#ifndef PATH_DELIM
# define PATH_DELIM '/'
#endif

char	*path_cat(char *dest, const char *a, const char *b);
char	*ft_basename(const char *path);
