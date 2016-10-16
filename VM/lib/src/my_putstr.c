/*
** my_putstr.c for my_putstr.c in /home/soto_a/rendu/Piscine_C_J04
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Thu Oct  2 12:00:20 2014 adam kaso
** Last update Fri Jan 16 17:22:35 2015 Kaso Soto
*/

#include "my.h"

int	my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
  return (0);
}
