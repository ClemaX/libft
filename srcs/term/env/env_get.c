#include <term/env.h>

/*
** Get an environment variable using it's key.
**
** returns a pointer to the variable's value if it is found or NULL otherwise.
*/
const char		*env_get(t_env *env, const char *key, size_t key_length)
{
	while (env && (key_length != env->key_length
	|| ft_strncmp(env->key, key, env->key_length)))
		env = env->next;
	if (env)
		return (env->key + key_length + 1);
	return (NULL);
}

/*
** Export the environment to a c-string array.
**
** returns a NULL-terminated array of the exported environment variables,
** or NULL in case of error.
*/
const char		**env_export(t_env *env)
{
	size_t		length;
	t_env		*current;
	const char	**strs;

	length = 0;
	current = env;
	while (current)
	{
		if (current->exported)
			length++;
		current = current->next;
	}
	strs = malloc(sizeof(*strs) * (length + 1));
	if (strs)
	{
		current = env;
		strs[length--] = NULL;
		while (current && length >= 0)
		{
			if (current->exported)
				strs[length--] = current->key;
			current = current->next;
		}
	}
	return (strs);
}
