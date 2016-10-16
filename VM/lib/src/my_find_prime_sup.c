/*
** my_find_prime_sup.c for my_find_prime_sup.c in /home/soto_a/rendu/Piscine_C_J05
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 16:59:35 2014 adam kaso
** Last update Fri Dec  5 14:47:11 2014 Kaso Soto
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  int	result;
  int	i;

  i = 2;
  while (i < nb)
    {
      result = nb / i;
      if (result * i == nb)
	{
	  nb++;
	  i = 1;
	}
      i++;
    }
  return (nb);
}
