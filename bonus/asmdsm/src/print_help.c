/*
** print_help.c for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 17:22:48 2015 Manuel Trambert
** Last update Sun Apr 12 17:26:42 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "string_error.h"
#include "my.h"

void	print_cmd_help(int i)
{
  my_putstr("to the command: ", 1);
  my_putstr(g_string_param_err[i][0], 1);
  my_putstr("\n\tit take as first argument: ", 1);
  my_putstr(g_string_param_err[i][1], 1);
  if (g_string_param_err[i][2] != NULL)
    {
      my_putstr("\n\tit take as second argument: ", 1);
      my_putstr(g_string_param_err[i][2], 1);
    }
  if (g_string_param_err[i][3] != NULL)
    {
      my_putstr("\n\tit take as third argument: ", 1);
      my_putstr(g_string_param_err[i][3], 1);
    }
  if (g_string_param_err[i][4] != NULL)
    {
      my_putstr("\n\tit take as fourth argument: ", 1);
      my_putstr(g_string_param_err[i][4], 1);
    }
  my_putchar('\n', 1);
}

void	print_every_help()
{
  int	i;

  i = 0;
  while (g_string_param_err[i][0] != NULL)
    {
      print_cmd_help(i);
      i += 1;
    }
}

void	print_help(char	*str)
{
  int	i;

  i = 0;
  while (g_string_param_err[i][0] != NULL
	 && my_strcmp(g_string_param_err[i][0], str) == 0)
    i += 1;
  if (g_string_param_err[i][0] == NULL)
    print_every_help();
  else
    print_cmd_help(i);
}
