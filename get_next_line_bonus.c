/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:08:10 by schoukou          #+#    #+#             */
/*   Updated: 2021/12/11 03:26:28 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*after_new_line( char *buf)
{
	char	*remind;
	int		j;

	j = 0;
	if (!buf)
		return (NULL);
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
	if (!buf[0])
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
	if (!rsv)
		return (NULL);
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
	static char		*buf[1024];
	char			*line;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = get_line(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = cut(buf[fd]);
	buf[fd] = after_new_line(buf[fd]);
	return (line);
}
