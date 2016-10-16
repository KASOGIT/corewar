/*
** my_is_prime.c for my_is_prime.c in /home/soto_a/rendu/Piscine_C_J05
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 16:16:46 2014 adam kaso
** Last update Fri Dec  5 14:48:17 2014 Kaso Soto
*/

#include "my.h"

int	my_is_prime(int nb)
{
  int	i;
  int	result;

  i = 2;
  if (nb <= 0 || nb == 1)
    return (0);
  while (i < nb)
    {
      result = nb / i;
      if (result * i == nb)
	return (0);
      i++;
    }
  return (1);
}
