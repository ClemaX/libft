#pragma once

#ifndef OPT_PREFIX
# define OPT_PREFIX '-'
#endif

#ifndef OPT_ILLEGAL
# define OPT_ILLEGAL "illegal option --"
#endif

#define OPT_ERROR -1

typedef struct	s_opt_def
{
	const char	*short_opts;
	const char	**long_opts;
	const char	**desc;
	const char	*usage;
}				t_opt_def;

int				opts_get(const t_opt_def *const def, int *const i,
	const char *const *const av);

void			opts_usage(const t_opt_def *const def, const char *prog);
