/*
** print.c for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 17:20:42 2015 Manuel Trambert
** Last update Sun Apr 12 17:21:07 2015 Manuel Trambert
*/

#include "my.h"

void	print_register(unsigned char *str, int *i, int fd)
{
  int	num_reg;

  *i += 1;
  num_reg = str[*i];
  my_putchar('r', fd);
  my_put_nbr(num_reg, fd);
}

int	print_dir(unsigned char *str, int *i,
		  __attribute__((unused))int loop, int fd)
{
  int	value;
  int	neg;

  *i += 1;
  neg = 0;
  if (str[*i] == 255)
    neg = -256;
  else if (str[*i] == 1)
    neg = 256;
  if (str[*i] == 254)
    neg = -512;
  *i += 1;
  value = str[*i] + neg;
  my_put_nbr(value, fd);
  return (*i);
}

int	print_ind(unsigned char *str, int *i,
		  __attribute__((unused))int loop, int fd)
{
  int	value;

  value = 0;
  *i += 1;
  value = litle_to_big(*(int*)&str[*i]);
  *i += 3;
  my_putchar('%', fd);
  my_put_nbr((int)value, fd);
  return (*i);
}
