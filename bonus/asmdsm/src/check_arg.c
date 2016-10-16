/*
** check_arg.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr  4 20:54:51 2015 Manuel Trambert
** Last update Sat Apr 11 04:22:13 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my.h"

int	check_arg(char *str, int line, char **text, int type)
{
  int	test;
  int	i;

  i = 0;
  if (str == NULL)
    {
      my_putstr("You should give argument to your command line: \n", 2);
      my_put_nbr(line, 2);
      return (-1);
    }
  while (g_type_func[i].type != 0 && g_type_func[i].type != type)
    i += 1;
  if (g_type_func[i].type != 0)
    {
      if (type <= 4 && type != 3)
	test = g_type_func[i].type_fct(str, line, text, 0);
      else
	test = g_type_func[i].type_fct(str, line, text, 1);
    }
  if (test != 0)
    return (-1);
  return (0);
}

int	check_mul_arg(char **tab, int line, char **text, int i)
{
  int	nb;
  int	e;
  char	*tmp;
  int	bool;
  char	**parameter;

  nb = 0;
  e = (islabel(tab[0]) == 1) ? 1 : 0;
  tmp = kill_space(tab[e + 1]);
  parameter = cut_parameter(tmp);
  bool = 0;
  while (nb < op_tab[i].nbr_args)
    {
      if ((check_arg(parameter[nb], line, text, op_tab[i].type[nb])) == -1)
	bool = -1;
      nb += 1;
    }
  free(tmp);
  free(parameter);
  if (bool == -1)
    return (-1);
  return (0);
}
