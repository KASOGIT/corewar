/*
** label.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 03:49:59 2015 Manuel Trambert
** Last update Sat Apr 11 04:23:09 2015 Manuel Trambert
*/

#include "my.h"

int	size_new_label(char **text, int i)
{
  int	e;

  e = 0;
  while (text[i] != NULL && islabel(text[i]) != 1)
    {
      i += 1;
      e += 1;
    }
  return (e);
}

int	check_label(char *str)
{
  int	i;

  i = 0;
  if (islabel(str) == 0)
    return (1);
  while (str[i] != ':')
    i += 1;
  if (str[i] == '\0')
    return (-1);
  if (check_null(str + i + 1) == 0)
    return (1);
  else
    return (-1);
  return (1);
}

int	param_islabel(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ':' && str[i - 1] == '%')
	return (1);
      i += 1;
    }
  return (0);
}

int	labelexist(char *str, char **text)
{
  int	i;

  i = 0;
  if (str[0] == '%')
    str += 2;
  else
    str += 1;
  while (text[i] != NULL)
    {
      if (islabel(text[i]) == 1)
	if (my_strncmp(str, text[i], my_strlen(str)) == 0
	    && text[i][my_strlen(str)] == ':')
	  return (0);
      i += 1;
    }
  return (-1);
}
