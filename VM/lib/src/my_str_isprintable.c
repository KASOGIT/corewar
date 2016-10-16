/*
** my_str_isprintable.c for my_str_isprintable.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 01:06:30 2014 adam kaso
** Last update Fri Dec  5 14:56:23 2014 Kaso Soto
*/

#include "my.h"

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 32 && str[i] <= 126))
	return (0);
      i++;
    }
  return (1);
}
