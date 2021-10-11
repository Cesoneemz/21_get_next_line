#include <stdlib.h>

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (*str++ != '\0')
		index++;
	return (index);
}

char	*ft_strchr(char *s, int c)
{
	const char	*str;

	str = s;
	if (!str)
		return (0);
	while (s >= str)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*buffer;
	size_t		s1len;
	size_t		s2len;
	size_t		index;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	buffer = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
		buffer[index++] = *s1++;
	while (*s2 != '\0')
		buffer[index++] = *s2++;
	buffer[index] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_get_line(char *str)
{
	int		index;
	char	*buffer;

	index = 0;
	if (!*str)
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	buffer = (char *)malloc((index + 2) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		buffer[index] = *str++;
		index++;
	}
	if (str[index] == '\n')
	{
		buffer[index] = str[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}
