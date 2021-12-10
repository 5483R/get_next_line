#ifndef     GET_NEXT_LINE_H
# define     GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <ctype.h>
# include <fcntl.h>

int	    checknewline(char *str);
int	    ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, unsigned int len);
char	*get_next_line(int fd);
#endif