#include <libft/strings.h>

static size_t	token_next(char *restrict *next, char *restrict *token, const char *delim)
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
	}
	while (delim[delim_i] != '\0' && (*next)[end_i] != '\0');

	if (delim[delim_i] == '\0' || (*next)[end_i] == '\0')
	{
		*token = *next;
		(*next) += end_i;

		if (end_i == delim_i)
		{
			end_i = 0;
			delim_i = 0;
		}
	}
	return (delim_i);
}

char	*ft_strtok(char *restrict str, const char *restrict delim)
{
	static char *restrict	start;
	size_t					delim_i;


	if (str != NULL)
		start = str;
	else
		str = start;
	if (*delim != '\0' && *start != '\0')
	{
		delim_i = token_next(&start, &str, delim);
		if (delim[delim_i] == '\0')
			start[-delim_i] = '\0';
	}
	if (str != NULL && *str == '\0')
		str = NULL;

	return (str);
}
