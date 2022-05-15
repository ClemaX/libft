#include <libft/strings.h>
#include <stddef.h>

#include <stdio.h>

static size_t	token_next(char *restrict *next, char *restrict *str, const char *delim)
{
	size_t	end_i;
	size_t	delim_i;

	end_i = 0;
	delim_i = 0;
	do
	{
		delim_i = 0;
		while (delim[delim_i] != '\0' && (*next)[end_i] == delim[delim_i])
		{
			end_i++;
			delim_i++;
		}
		if (delim[delim_i] != '\0')
			end_i++;
		else
		{
			*str = *next;
			(*next) += end_i;
			if (end_i == delim_i)
			{
				end_i = 0;
				delim_i = 0;
			}
		}
	}
	while (delim[delim_i] != '\0' && (*next)[end_i] != '\0');
	return (delim_i);
}

char	*ft_strtok(char *restrict str, const char *restrict delim)
{
	static char *restrict	token;
	size_t					delim_i;

	if (str != NULL)
		token = str;
	else
		str = token;
	if (*delim != '\0' && *token != '\0')
	{
		delim_i = token_next(&token, &str, delim);
		if (delim[delim_i] == '\0')
			token[-delim_i] = '\0';
		else
			str = NULL;
	}
	if (str != NULL && *str == '\0')
		str = NULL;
	return (str);
}
