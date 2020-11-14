#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <stdbool.h>
# include <libft.h>

# ifndef ENV_OP_ASSIGN
#  define ENV_OP_ASSIGN '='
# endif

typedef	struct	s_env
{
	char			*key;
	size_t			key_length;
	bool			exported;
	struct s_env	*next;
}				t_env;

size_t			env_key_len(const char *key);

const char		*env_set(t_env **env,
	const char *key, const char *value, bool exported);
char			env_assign(t_env **env, const char *assignment, bool exported);
t_env			*env_import(const char **envp);

const char		*env_get(t_env *env, const char *key, size_t key_length);

const char		**env_export(t_env *env);

void			env_clr(t_env **env);

#endif
