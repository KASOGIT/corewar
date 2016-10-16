/*
** my_isneg.c for my_isneg in /home/soto_a/rendu/Piscine_C_J03
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Oct  1 13:22:15 2014 adam kaso
** Last update Fri Dec  5 14:48:05 2014 Kaso Soto
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
