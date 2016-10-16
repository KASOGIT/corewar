/*
** my_square_root.c for my_power_rec.c in /home/soto_a/rendu/Piscine_C_J05
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 15:28:59 2014 adam kaso
** Last update Fri Dec  5 14:53:50 2014 Kaso Soto
*/

#include "my.h"

int	my_square_root(int nb)
{
  int	i;

  i = 0;
  if (nb == 1)
    return (1);
  while (i <= nb / 2)
    {
      if (i * i == nb)
	return (i);
      i++;
    }
  return (0);
}
