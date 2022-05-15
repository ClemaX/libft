#pragma once

#include <limits.h>
#include <stddef.h>

#ifndef PATH_DELIM
# define PATH_DELIM '/'
#endif

#ifndef PATH_DELIM_S
# define PATH_DELIM_S "/"
#endif

#ifndef PATH_PREV
# define PATH_PREV ".."
#endif

#ifndef PATH_CURR
# define PATH_CURR "."
#endif

#ifndef PATH_ROOT
# define PATH_ROOT PATH_DELIM_S
#endif

size_t	ft_baselen(const char *path);
char	*ft_basename(const char *path);
