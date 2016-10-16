/*
** tools.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:17 2015 Manuel Trambert
** Last update Fri Apr  3 11:58:18 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*my_strcpy(char *str, char *tmp)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '#')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

char	*my_strdup(char	*str)
{
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    exit(1);
  tmp = my_strcpy(str, tmp);
  return (tmp);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

void	my_putstr(char *str, int fd)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(fd, &str[i], 1);
      i += 1;
    }
}

int	my_strcmp(char *str, char *str1)
{
  int	i;

  i = 0;
  if (str == NULL || str1 == NULL)
    return (0);
  if (my_strlen(str) != my_strlen(str1))
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == str1[i])
	i += 1;
      else
	return (0);
    }
  return (1);
}
