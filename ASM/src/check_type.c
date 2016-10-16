/*
** check_type.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 04:21:49 2015 Manuel Trambert
** Last update Sat Apr 11 04:22:09 2015 Manuel Trambert
*/

#include "my.h"

int	check_reg_dir(char *str, int line, char **text, int bool)
{
  if (check_dir(str, line, text, bool) == -1
      && check_reg(str, line, text, bool) == -1)
    {
      my_putstr("Compile error: Should have direct or register line: ", 2);
      my_put_nbr(line);
      return (-1);
    }
  return (0);
}

int	check_reg_ind(char *str, int line, char **text, int bool)
{
  int	test;

  if ((test = check_ind(str, line, text, bool)) != 0
      && check_reg(str, line, text, bool) != 0)
   {
     if (test != -2 && test != -3)
       {
	 my_putstr("Compile error: Should have register or indirect line: ", 2);
	 my_put_nbr(line);
       }
     return (-1);
   }
  return (0);
}

int	check_dir_ind(char *str, int line, char **text, int bool)
{
  int	test;

  if (check_dir(str, line, text, bool) == -1
      && (test = check_ind(str, line, text, bool) != 0))
    {
      if (test != -2 && test != -3)
        {
          my_putstr("Compile error: should have direct or indirect line: ", 2);
          my_put_nbr(line);
        }
      return (-1);
    }
  return (0);
}

int	check_everytype(char *str, int line, char **text, int bool)
{
  int   test;

  if (check_dir(str, line, text, bool) == -1)
    if ((test = check_ind(str, line, text, bool)) != 0
	&& check_reg(str, line, text, bool) == -1)
      {
        if (test != -3 && test != -2)
          {
            my_putstr("Compile error: bad argument at line: ", 2);
            my_put_nbr(line);
          }
        return (-1);
      }
  return (0);
}

int	check_index(char *str)
{
  int	i;

  i = 0;
  while (g_cmd[i].name != NULL
	 && my_strncmp(g_cmd[i].name, str, my_strlen(g_cmd[i].name)) != 0)
    i += 1;
  return (g_cmd[i].ret);
}
