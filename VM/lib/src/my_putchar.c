/*
** my_putchar.c for my_putchar in /home/soto_a/my_funcs
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Oct  1 10:04:23 2014 adam kaso
** Last update Fri Jan 16 14:28:51 2015 Kaso Soto
*/

#include "my.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
}
