/*
** my_power_rec.c for my_power_rec.c in /home/soto_a/rendu/Piscine_C_J05
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Oct  3 18:39:16 2014 adam kaso
** Last update Fri Dec  5 14:48:30 2014 Kaso Soto
*/

#include "my.h"

int	my_power_rec(int nb, int power)
{
  int	a;
  int	b;

  a = nb;
  b = power;
  if (b == 0)
    {
      return (1);
    }
  else if (a == 0 || b < 0 || b >= 12)
    {
      return (0);
    }
  else
    {
      return (a * my_power_rec(a, b - 1));
    }
}
