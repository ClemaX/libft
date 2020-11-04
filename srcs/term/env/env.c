#include <term/env.h>

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
