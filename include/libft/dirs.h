#pragma once

#include <libft/lists.h>

#define DIR_ISBACKREF(name) ((name)[0] == '.' && (((name)[1] == '.')\
	&& (name)[2] == '\0') || (name)[1] == '\0')

int	dir_load(t_list **files, const char *filepath, unsigned char filter);
int	dir_list(t_list **dirs, const char *filepath);
