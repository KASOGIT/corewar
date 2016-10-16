/*
** is.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:32 2015 Manuel Trambert
** Last update Fri Apr  3 11:58:33 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "op.h"

int	isnum(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if ((str[i] <= '9' && str[i] >= '0') || (str[i] == '-'))
	i += 1;
      else
	return (1);
    }
  return (0);
}

int	iscmd(char *str)
{
  int	bool;
  int	i;

  i = 0;
  while (op_tab[i].mnemonique != NULL
	 && (bool = my_strncmp(str, op_tab[i].mnemonique,
			       my_strlen(op_tab[i].mnemonique))) != 0)
    i += 1;
  return (bool);
}

int	islabel(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == ':' && (str[i - 1] != '%' && str[i - 1] != ' '))
	return (1);
      i += 1;
    }
  return (0);
}
