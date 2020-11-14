#include <term/env.h>

/*
** returns the character after an assignment's key
*/
size_t	env_key_len(const char *key)
{
	const char	*i;

	i = key;
	while(ft_isalnum(*i) || *i == '_' || *i == '-')
		i++;
	return (i - key);
}

/*
** Free the allocated environment.
*/
void	env_clr(t_env **env)
{
	t_env	*current;

	while ((current = *env))
	{
		*env = current->next;
		free(current->key);
		free(current);
	}
}
