/*
** my_putnbr.c for my_putnbr.c in /home/soto_a
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Nov 22 14:11:15 2014 Kaso Soto
** Last update Fri Dec  5 15:07:08 2014 Kaso Soto
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    {
      my_putchar('0' + nb);
    }
}
