#pragma once

#include <stdint.h>

#include <libft/lists.h>

#define DIR_ISBACKREF(name) \
	((name)[0] == '.' \
		&& ((((name)[1] == '.') && ((name)[2] == '\0')) \
		|| (name)[1] == '\0'))

# define DIR_OBACKREF	0b01
# define DIR_OBASENAME	0b10

typedef uint8_t	t_dir_opt;

typedef int (*t_dir_err_handler)(const char *filepath, int err, void *data);

int		dir_add(t_list **files, const char *filepath);
void	dir_del(void *data);

int		dir_load(t_list **files, const char *filepath,
	unsigned char filter, t_dir_opt options);
int		dir_list(t_list **dirs, const char *filepath,
	t_dir_err_handler on_error, void *data);
