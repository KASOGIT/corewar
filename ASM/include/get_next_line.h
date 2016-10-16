/*
** get_next_line.h for  in /home/trambe_m/CPE_2014_get_next_line/include
**
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
**
** Started on  Mon Nov 17 13:35:42 2014 Manuel Trambert
** Last update Sat Nov 22 06:22:05 2014 Manuel Trambert
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_

# define BUFFER 4096
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		my_strlen(const char *str);
char		*my_realloc(char *src);
char		get_char(const int fd);
char		*my_free(char *line);
char		*get_next_line(const int fd);
void		my_putchar(char e);
void		my_putstr(char *str, int fd);

#endif /* !GET_NEXT_LINE_ */
