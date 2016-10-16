/*
** size_parameter.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:20 2015 Manuel Trambert
** Last update Sat Apr 11 04:38:33 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "op.h"

int	size_sti(char *str)
{
  int	i;
  int	bool;
  char	**parameter;
  char	**line;

  i = -1;
  bool = 0;
  line = my_str_to_wordtab(str);
  if (islabel(str) != 1)
    parameter = cut_parameter(line[1]);
  else
    parameter = cut_parameter(line[2]);
  while (parameter[++i] != NULL)
    if (parameter[i][0] == 'r')
      bool += 1;
  free_tab(parameter);
  free_tab(line);
  if (bool == 3)
    return (5);
  else if (bool == 1)
    return (7);
  return (6);
}

int	get_size_parameter(char *str)
{
  if (str[0] == 'r')
    return (1);
  else if (str[0] == '%' && str[1] == ':')
    return (2);
  else if (str[0] == '%' && isnum(str + 1) == 0)
    return (4);
  else if (str[0] != '%' && isnum(str) == 0)
    return (2);
  return (0);
}

int	size_mul_param(char **parameter)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  while (parameter[i] != NULL)
    {
      size += get_size_parameter(parameter[i]);
      i += 1;
    }
  return (size);
}

int	size_line(char *str)
{
  int	size;
  char	**parameter;

  size = 0;
  if (islabel(str) == 1)
    return (0);
  else if (iscmd(str) == 0)
    size = check_index(str);
  if (size == 0)
    {
      parameter = cut_parameter(str);
      size += size_mul_param(parameter);
      free_tab(parameter);
    }
  return (size);
}

int	size_parameter(t_champ *champ)
{
  int	i;
  int	e;
  int	size;
  char	**line;

  i = -1;
  size = 0;
  while (champ->label[++i] != NULL)
    {
      line = my_str_to_wordtab(champ->label[i]);
      e = 0;
      if (check_index(line[e]) == 0)
	{
	  while (line[++e] != NULL)
	    size += size_line(line[e]);
	  size += 2;
	}
      else if (check_index(line[e]) == -1 || check_index(line[e]) == -2)
	size += size_sti(champ->label[i]);
      else
	size += size_line(line[e]) + 1;
      free_tab(line);
    }
  return (size);
}
