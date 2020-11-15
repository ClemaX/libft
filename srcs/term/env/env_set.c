#include <term/env.h>

/*
** Get an entry in a given environment using it's key.
**
** returns a pointer to the entry or NULL in case of error.
*/
static t_env	*env_get_entry(t_env **env, const char *key, size_t key_length)
{
	t_env	*curr;

	curr = *env;
	while (curr && (key_length != curr->key_length
	|| ft_strncmp(curr->key, key, curr->key_length)))
		curr = curr->next;
	if (!curr && (curr = malloc(sizeof(*curr))))
	{
		curr->exported = false;
		curr->key = NULL;
		curr->key_length = 0;
		curr->next = *env;
		*env = curr;
	}
	return (curr);
}

/*
** Assign an environment variable using an assignment operation.
**
** The assignment string should be composed of [KEY]=[VALUE].
** The key's characters must be alphanumeric or '-' and '_'.
**
** returns 0 if the assignment is invalid, 1 if successful and -1 otherwise.
*/
char		env_assign(t_env **env, const char *assignment, bool exported)
{
	size_t			key_len = env_key_len(assignment);
	t_env			*entry;

	if (!key_len || assignment[key_len] != ENV_OP_ASSIGN)
		return (0);
	if (!(entry = env_get_entry(env, assignment, key_len)))
		return (-1);
	free(entry->key);
	if (!(entry->key = ft_strdup(assignment)))
		return (-1);
	entry->exported = exported;
	entry->key_length = key_len;
	return (1);
}

/*
** Set an environment variable using a key a value and an export flag.
**
** returns a pointer to the value that has been set successfully, or NULL
** otherwise.
*/
const char		*env_set(t_env **env,
	const char *key, const char *value, bool exported)
{
	const size_t	key_length = ft_strlen(key);
	const size_t	value_length = ft_strlen(value);
	t_env			*entry;
	size_t			data_size;

	if (!(entry = env_get_entry(env, key, key_length)))
		return (NULL);
	free(entry->key);
	entry->exported = exported;
	entry->key_length = key_length;
	data_size = key_length + value_length + 2;
	if (!(entry->key = malloc(sizeof(*entry->key) * data_size)))
		return (NULL);
	ft_memcpy(entry->key, key, entry->key_length);
	entry->key[entry->key_length] = ENV_OP_ASSIGN;
	ft_memcpy(entry->key + entry->key_length + 1, value, value_length);
	entry->key[data_size - 1] = '\0';
	return (entry->key + entry->key_length + 1);
}

/*
** Load environment variables from a NULL-terminated c-string array.
**
** returns a pointer to the environment,
** or NULL in case of error.
*/
t_env			*env_import(const char **envp)
{
	t_env	*env;

	env = NULL;
	while (*envp)
	{
		if (!(env_assign(&env, *envp++, true)))
		{
			env_clr(&env);
			return (NULL);
		}
	}
	return (env);
}
