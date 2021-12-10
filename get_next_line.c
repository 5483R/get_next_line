#include "get_next_line.h"

char	*after_new_line( char *buf)
{
	char	*remind;
	int		j;

	j = 0;
	if (!buf)
		return(NULL);
	while (buf[j])
	{
		if (buf[j] == '\n')
		{
			remind = ft_substr(buf, j + 1, ft_strlen(buf));
			free(buf);
			return (remind);
		}
		j++;
	}
	free(buf);
	return (NULL);
}
char	*cut(char *buf)
{
	int	j;

	j = 0;
	if(!buf[0])
		return (NULL);
	while (buf[j] && buf[j] != '\n')
		j++;
	return (ft_substr(buf, 0, j + 1));
}
char	*get_line(int fd, char *buf)
{
	char	*rsv;
	int		i;

	rsv = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if(!rsv)
		return NULL;
	i = 1;
	while (!checknewline(buf) && i)
	{
		i = read(fd, rsv, BUFFER_SIZE);
		if (i == -1)
		{
			free(rsv);
			return (NULL);
		}
		rsv[i] = '\0';
		buf = ft_strjoin(buf, rsv);
	}
	free (rsv);
	return (buf);
}
char	*get_next_line(int fd)
{
	int				i;
	static char		*buf;
	char			*line;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	buf = get_line(fd, buf);
	if (!buf)
		return (NULL);
	line = cut(buf);
	buf = after_new_line(buf);
	return (line);
}

// int main(void)
// {
//     int     fd;

//     fd = open("saber.txt", O_RDONLY);
    
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("\n%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));


//     return (0);
// }