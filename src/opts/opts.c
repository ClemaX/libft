#include <stdbool.h>
#include <unistd.h>

#include <libft/strings.h>
#include <libft/io.h>

#include <libft/opts.h>

static int	opt_params(const opt_spec *spec, const char **av, int *ai,
	void *data, size_t param_offset)
{
	const char *	parser_error;

	av[*ai] += param_offset;
	parser_error = spec->parser(av, ai, data);
	av[*ai] -= param_offset;

	if (parser_error != NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", av[0], parser_error);

		return OPT_ERROR;
	}

	return 0;
}

static int	opt_flag_long(const opt_spec *specs, unsigned spec_count,
	const char *flag, size_t *flag_len)
{
	unsigned	spec_i;

	*flag_len = ft_strchrnul(flag, OPT_ASSIGN) - flag;

	for
	(
		spec_i = 0;
		spec_i < spec_count
			&& specs[spec_i].long_flag != NULL
			&& (ft_strlen(specs[spec_i].long_flag) != *flag_len
				|| ft_strncmp(specs[spec_i].long_flag, flag, *flag_len) != 0);
		++spec_i
	);

	if (spec_i == spec_count)
		return OPT_ERROR;

	return spec_i;
}

static int	opt_flag_short(const opt_spec *specs, unsigned spec_count,
	char flag)
{
	unsigned	spec_i;

	for
	(
		spec_i = 0;
		spec_i < spec_count && specs[spec_i].short_flag != flag;
		++spec_i
	);

	if (spec_i == spec_count)
		return OPT_ERROR;

	return spec_i;
}

int	opts_get(const opt_spec *specs, unsigned spec_count,
	const char **av, int *ai, void *data)
{
	size_t	flag_len;
	size_t	param_offset;
	int		opts;
	int		spec_i;
	int		flag_i;

	opts = 0;
	spec_i = OPT_ERROR;

	while (av[*ai] != NULL)
	{
		if (av[*ai][0] != OPT_PREFIX)
		{
			++(*ai);
			continue;
		}

		flag_i = 1;
		param_offset = 0;

		if (av[*ai][flag_i] == OPT_PREFIX)
		{
			++flag_i;

			if (av[*ai][flag_i] == '\0')
				break;

			spec_i = opt_flag_long(specs, spec_count,
				av[*ai] + flag_i, &flag_len);

			if (spec_i == OPT_ERROR)
			{
				ft_dprintf(STDERR_FILENO, "%s: "OPT_ILLEGAL": '%s'\n",
					av[0], av[*ai] + flag_i);

				return OPT_ERROR;
			}

			if (av[*ai][flag_i + flag_len] == OPT_ASSIGN)
			{
				if (specs[spec_i].parser == NULL)
				{
					ft_dprintf(STDERR_FILENO,
						"%s: "OPT_PARAM_UNEXPECTED": '%s'\n",
						av[0], av[*ai] + flag_i);

					return OPT_ERROR;
				}
				param_offset = flag_i + flag_len + 1;
			}
			else
				++(*ai);

			opts |= 1 << spec_i;
		}
		else
		{
			while (av[*ai][flag_i] != '\0')
			{
				spec_i = opt_flag_short(specs, spec_count, av[*ai][flag_i]);

				if (spec_i == OPT_ERROR)
				{
					ft_dprintf(STDERR_FILENO, "%s: "OPT_ILLEGAL": '%c'\n",
						av[0], av[*ai][flag_i]);

					return OPT_ERROR;
				}

				++flag_i;
				opts |= 1 << spec_i;

				if (specs[spec_i].parser != NULL)
					break;
			}

			if (av[*ai][flag_i] != '\0')
				param_offset = flag_i;
			else
				++(*ai);
		}
		if (spec_i != OPT_ERROR && specs[spec_i].parser != NULL
			&& opt_params(&specs[spec_i], av, ai, data, param_offset)
				== OPT_ERROR)
			return OPT_ERROR;
	}

	return opts;
}

void		opts_usage(const opt_spec *const specs, unsigned spec_count,
	const char *progname, const char *suffix)
{
	const char	*params;

	ft_dprintf(STDERR_FILENO, "Usage: %s [options]%s\n", progname, suffix);

	for (unsigned spec_i = 0; spec_i < spec_count; ++spec_i)
	{
		if (specs[spec_i].parser != NULL)
			params = specs[spec_i].parser(NULL, NULL, NULL);
		else
			params = NULL;

		if (specs[spec_i].short_flag != '\0')
		{
			if (specs[spec_i].long_flag == NULL)
			{
				if (params == NULL)
					ft_dprintf(STDERR_FILENO, " -%-22c%s\n",
						specs[spec_i].short_flag,
						specs[spec_i].description);
				else
					ft_dprintf(STDERR_FILENO, " -%c %-22s%s\n",
						specs[spec_i].short_flag,
						params,
						specs[spec_i].description);
			}
			else
			{
				if (params == NULL)
					ft_dprintf(STDERR_FILENO, " -%c, --%-18s%s\n",
						specs[spec_i].short_flag,
						specs[spec_i].long_flag,
						specs[spec_i].description);
				else
					ft_dprintf(STDERR_FILENO, " -%c, --%s=%*s%s\n",
						specs[spec_i].short_flag,
						specs[spec_i].long_flag,
						(int)ft_strlen(specs[spec_i].long_flag) - 17, params,
						specs[spec_i].description);
			}
		}
		else if (specs[spec_i].long_flag != NULL)
		{
			if (params == NULL)
				ft_dprintf(STDERR_FILENO, "     --%-18s%s\n",
						specs[spec_i].long_flag,
						specs[spec_i].description);
			else
				ft_dprintf(STDERR_FILENO, "     --%s=%*s%s\n",
						specs[spec_i].long_flag,
						(int)ft_strlen(specs[spec_i].long_flag) - 17, params,
						specs[spec_i].description);
		}
	}
}
