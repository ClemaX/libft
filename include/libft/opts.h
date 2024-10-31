#pragma once

#ifndef OPT_PREFIX
# define OPT_PREFIX '-'
#endif

#ifndef OPT_ASSIGN
# define OPT_ASSIGN '='
#endif

#ifndef OPT_ILLEGAL
# define OPT_ILLEGAL "illegal option"
#endif

#ifndef OPT_PARAM_UNEXPECTED
# define OPT_PARAM_UNEXPECTED "unexpected parameter"
#endif

#define OPT_ERROR -1

typedef const char *(opt_parser(const char **av, int *ai, void *data));

typedef struct	opt_spec
{
	const char	*long_flag;
	opt_parser	*parser;
	const char	*description;
	char		short_flag;
}				opt_spec;

int				opts_get(const opt_spec *specs, unsigned spec_count,
	const char **av, int *ai, void *data);

void			opts_usage(const opt_spec *const specs, unsigned spec_count,
	const char *prog, const char *suffix);
