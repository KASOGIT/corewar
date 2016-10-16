/*
** get_next_line.c for  in /home/trambe_m/CPE_2014_get_next_line/src
**
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
**
** Started on  Fri Nov 21 21:16:47 2014 Manuel Trambert
** Last update Sun Nov 23 04:08:26 2014 Manuel Trambert
*/

#include "get_next_line.h"

char		*my_realloc(char *src)
{
  char		*dest;
  int		i;

  i = 0;
  if ((dest = malloc(sizeof(char) * (BUFFER + my_strlen(src) + 1))) == NULL)
    exit(0);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i + BUFFER] = '\0';
  free(src);
  return (dest);
}

char		get_char(const int fd)
{
  static char	buffer[BUFFER + 1];
  static int	i = 0;
  static int	j = 0;

  if (i == 0 || i == j)
    {
      j = read(fd, buffer, BUFFER);
      i = 0;
      buffer[j] = '\0';
    }
  if (j <= 0)
    return (0);
  else
    return (buffer[i++]);
}

char		*my_free(char *line)
{
  free(line);
  return (NULL);
}

char		*get_next_line(const int fd)
{
  int		i[2];
  char		e;
  char		*line;

  i[0] = 0;
  i[1] = BUFFER;
  if (((line = malloc(sizeof(char) * (BUFFER + 1))) == NULL) || fd < 0)
    return (NULL);
  line[BUFFER] = '\0';
  while ((e = get_char(fd)))
    {
      if (e == '\n' && !(line[i[0]] = '\0'))
	return (line);
      if (i[1]-- == 0)
	{
	  line = my_realloc(line);
	  i[1] = BUFFER;
	}
      line[(i[0])++] = e;
    }
  line[i[0]] = '\0';
  return ((i[0] != 0) ? line : my_free(line));
}
