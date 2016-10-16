/*
** my_showstr.c for my_showstr.c in /home/soto_a/rendu/Piscine_C_J06/ex_17
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 17:59:16 2014 adam kaso
** Last update Sun Apr 12 05:52:01 2015 KASO soto
*/

#include "my.h"

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  my_putchar('\\');
	  if (str[i] < 14)
	    my_putchar('0');
	  my_putnbr_base(str[i], "0123456789abcdef", 0);
	}
      else
	{
	  my_putchar(str[i]);
	}
      i++;
    }
  return (0);
}
