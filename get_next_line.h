#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>



char	*get_next_line(int fd);

char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin_modified(char const *s1, char const *s2, int len2);
#endif