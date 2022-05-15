#include <unistd.h>

#include <libft/strings.h>
#include <libft/io.h>

#include <libft/opts.h>

static int	opt_long(const char *name,
	const char *const *const long_opts)
{
	int	option;

	option = 0;
	while (long_opts[option] != NULL && ft_strcmp(long_opts[option], name) != 0)
		option++;
	if (long_opts[option] != NULL)
		option = 1 << option;
	else
		option = OPT_ERROR;
	return (option);
}

static int	opt_short(char c, const char *const short_opts)
{
	const int	i = ft_strpos(short_opts, c);
	int	option;

	if (i != OPT_ERROR)
			option = 1 << i;
	else
			option = OPT_ERROR;
	return (option);
}

int			opts_get(const t_opt_def *const def, int *const i,
	const char *const *const av)
{
	int	opts;
	int	opt;
	size_t		j;

	opts = 0;
	j = 0;
	while (opts != OPT_ERROR && av[*i] != NULL && av[*i][j] == OPT_PREFIX)
	{
		++j;
		if (av[*i][j] == OPT_PREFIX)
		{
			++j;
			opt = opt_long(av[*i] + j, def->long_opts);
			if (opt != OPT_ERROR)
				opts |= opt;
			else
			{
				opts = opt;
				ft_dprintf(STDERR_FILENO, "%s: "OPT_ILLEGAL" %s\n",
					av[0], av[*i] + j);
			}
		}
		else
		{
			while (opts != OPT_ERROR && av[*i][j] != '\0')
			{
				opt = opt_short(av[*i][j], def->short_opts);
				if (opt != OPT_ERROR)
				{
					opts |= opt;
					++j;
				}
				else
				{
					opts = opt;
					ft_dprintf(STDERR_FILENO, "%s: "OPT_ILLEGAL" %c\n",
						av[0], av[*i][j]);
				}
			}
		}
		(*i)++;
		j = 0;
	}
	return (opts);
}

void		opts_usage(const t_opt_def *const def, const char *prog)
{
	const char      *fmt;
	unsigned        i;

	ft_dprintf(2, def->usage, prog, def->short_opts);
	i = 0;
	while (def->short_opts[i])
	{
		if (def->long_opts[i] == NULL)
			fmt = " -%c%-22.0s%s\n";
		else
			fmt = " -%c, --%-18s%s\n";
		ft_dprintf(2, fmt, def->short_opts[i], def->long_opts[i], def->desc[i]);
		i++;
	}
}
