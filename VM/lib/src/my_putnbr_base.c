/*
** my_putnbr_base.c for my_putnbr_base.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 09:51:33 2014 adam kaso
** Last update Sun Apr 12 05:49:10 2015 KASO soto
*/

#include "my.h"

int	my_putnbr_base(int nbr, char *base, int step)
{
  int	count;
  int	result;
  int	div;
  int	size_base;

  count = 0;
  div = 1;
  size_base = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  while (nbr / div >= size_base)
    div *= size_base;
  while (div > 0)
    {
      count++;
      result = (nbr / div) % size_base;
      my_putchar(base[result]);
      if (step + count == 32)
	{
	  my_putchar('\n');
	  step = 0;
	  count = 0;
	}
      div /= size_base;
    }
  return (count);
}
