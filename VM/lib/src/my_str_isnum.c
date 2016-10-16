/*
** my_str_isnum.c for my_str_isnum.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 00:46:42 2014 adam kaso
** Last update Fri Dec  5 14:56:11 2014 Kaso Soto
*/

#include "my.h"

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      i++;
    }
  return (1);
}
