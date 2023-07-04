#include <stdlib.h>
#include <dirent.h>

#include <libft/strings.h>
#include <libft/paths.h>

#include <libft/dirs.h>

int	dir_add(t_list **files, const char *filepath)
{
	const size_t	content_size = ft_strlen(filepath) + 1;
	t_list			*elem;
	int				err;

	elem = malloc(sizeof(*elem) + content_size);
	err = elem == NULL;
	if (err == 0)
	{
		elem->next = NULL;
		elem->content = (void *)(elem + 1);
		ft_strlcpy((char *)elem->content, filepath, content_size);
		ft_lstadd_back(files, elem);
	}
	return (err);
}

int	dir_load(t_list **files, const char *filepath,
	unsigned char filter, t_dir_opt options)
{
	char			full_path[PATH_MAX];
	const char		*path;
	DIR				*dir;
	struct dirent	*ent;
	int				err;

	dir = opendir(filepath);
	err = dir == NULL;
	if (err == 0)
	{
		do
		{
			ent = readdir(dir);

			if (ent != NULL
				&& (filter == DT_UNKNOWN || filter == ent->d_type)
				&& ((options & DIR_OBACKREF) || !DIR_ISBACKREF(ent->d_name)))
			{
				if ((options & DIR_OBASENAME) || (filepath[0] == '.' && filepath[1] == '\0'))
					path = ent->d_name;
				else
					path = path_cat(full_path, filepath, ent->d_name);

				err = dir_add(files, path);
			}
		}
		while (err == 0 && ent != NULL);
		closedir(dir);
	}
	return (err);
}

int	dir_list(t_list **list, const char *filepath)
{
	t_list	*curr;
	t_list	*dirs;
	t_list	*subdirs;
	int		err;

	dirs = NULL;
	err = dir_load(&dirs, filepath, DT_DIR, 0);
	if (err == 0)
	{
		subdirs = NULL;
		curr = dirs;
		while (err == 0 && curr != NULL)
		{
			err = dir_list(&subdirs, (const char *)curr->content);
			curr = curr->next;
		}
		if (subdirs != NULL)
			ft_lstadd_back(&dirs, subdirs);
	}
	if (err == 0)
		ft_lstadd_back(list, dirs);
	else
		ft_lstclear(&dirs, NULL);
	return (err);
}

void dir_del(void *data)
{
	(void)data;
}
