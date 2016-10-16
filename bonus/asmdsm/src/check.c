/*
** check.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:37 2015 Manuel Trambert
** Last update Fri Apr  3 11:58:37 2015 Manuel Trambert
*/

#include <stdlib.h>

int	check_line(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    if (tab[i][0] == ' ' || tab[i][0] == '\t'
	|| tab[i][0] == '\0')
      i += 1;
    else
      return (1);
  return (0);
}

int	check_null(char *str)
{
  int	i;
  int	bool;

  i = 0;
  bool = 1;
  while (str[i] != '\0')
    {
      if (str[i] != '\t' && str[i] != ' ')
	bool = 0;
      i += 1;
    }
  return (bool);
}
