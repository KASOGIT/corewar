/*
** check_parameter.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr  4 20:54:01 2015 Manuel Trambert
** Last update Sat Apr 11 03:59:16 2015 Manuel Trambert
*/

#include "my.h"

int	check_dir(char *str, int line, char **text, int bool)
{
  if (str[0] == '%' && str[1] == ':')
    {
      if (labelexist(str, text) != 0)
	{
	  my_putstr("Compile error: label called doesn't exist at line: ", 2);
	  my_put_nbr(line);
	  return (-2);
	}
      else
	return (0);
    }
  else if (str[0] == '%' && isnum(str + 1) == 0)
    return (0);
  if (bool == 0)
    {
      my_putstr("Compile error: Asking for direct line: ", 2);
      my_put_nbr(line);
    }
  return (-1);
}

int	check_ind(char *str, int line, char **text, int bool)
{
  if (str[0] == ':')
    {
      if (labelexist(str, text) != 0)
	{
	  my_putstr("Compile error: label called doesn't exist at line: ", 2);
	  my_put_nbr(line);
	  return (-3);
	}
      else
	return (0);
    }
  else if (isnum(str) == 0)
    return (0);
  if (bool == 0)
    {
      my_putstr("Compile error: Asking for indirect line: ", 2);
      my_put_nbr(line);
      return (-1);
    }
  return (-1);
}

int	check_reg(char *str, int line,
		  __attribute__((unused))char **text, int bool)
{
  if (str[0] == 'r' && str[1] != '\0' && my_get_nbr(str + 1) <= 16)
    return (0);
  else if (str[0] == 'r' && my_get_nbr(str + 1) > 16)
    {
      my_putstr("Compile error: Only 16 register available, line: ", 2);
      my_put_nbr(line);
      return (-2);
    }
  else if (str[0] != 'r')
    {
      if (bool == 0)
	{
	  my_putstr("Compile error: Asking for register line: ", 2);
          my_put_nbr(line);
	}
      return (-1);
    }
  else
    if (bool == 0)
      {
	my_putstr("Compile error: Asking for register line: ", 2);
	my_put_nbr(line);
      }
  return (-1);
}
