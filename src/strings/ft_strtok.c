#include <libft/strings.h>
#include <stddef.h>

static inline char	*delims_skip(char *restrict str, const char *restrict delim, size_t delim_len)
{
	size_t	i;

	i = 0;
	while (str[i] == delim[i % delim_len])
		++i;
	if (i % delim_len != 0)
		i -= i % delim_len;
	return (str + i);
}

static inline char	*delim_find(char *restrict str, const char *restrict delim)
{
	size_t	delim_i;

	do
	{
		delim_i = 0;
		while (*str != '\0' && *str != delim[0])
			++str;
		while (str[delim_i] == delim[delim_i])
			++delim_i;
		if (delim[delim_i] != '\0')
			str += delim_i;
	}
	while (*str!= '\0' && delim[delim_i] != '\0');
	return (str);
}


char			*ft_strtok(char *restrict str, const char *restrict delim)
{
	static char *restrict	start;
	size_t					delim_len;

	if (str != NULL)
		start = str;
	else
		str = start;
	if (*delim != '\0' && *start != '\0')
	{
		delim_len = ft_strlen(delim);
		str = delims_skip(str, delim, delim_len);
		start = delim_find(str, delim);
		if (*start != '\0')
		{
			*start = '\0';
			start += delim_len;
		}
	}
	if (str != NULL && *str == '\0')
		str = NULL;
	return (str);
}
