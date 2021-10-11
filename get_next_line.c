#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char	*ft_new_str(char *str)
{
	int		index;
	int		jndex;
	char	*buffer;

	index = 0;
	while (str[index] && str[index] != '\0')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	buffer = (char *)malloc((ft_strlen(str) - index + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index++;
	jndex = 0;
	while (str[index])
		buffer[jndex++] = str[index++];
	buffer[jndex] = '\0';
	free(str);
	return (buffer);
}

char	*ft_read_to_str(int fd, char *str)
{
	char		*buffer;
	int			rd_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 0) * sizeof(char));
	if (buffer == NULL)
		return (0);
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (!fd || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_to_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str(str);
	return (line);
}
