/*
** my_str_islower.c for my_str_islower.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 00:59:16 2014 adam kaso
** Last update Fri Dec  5 14:55:59 2014 Kaso Soto
*/

#include "my.h"

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'a' && str[i] <= 'z'))
	return (0);
      i++;
    }
  return (1);
}
