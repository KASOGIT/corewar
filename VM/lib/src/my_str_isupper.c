/*
** my_str_isupper.c for my_str_isupper.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 01:02:41 2014 adam kaso
** Last update Fri Dec  5 14:56:32 2014 Kaso Soto
*/

#include "my.h"

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'A' && str[i] <= 'Z'))
	return (0);
      i++;
    }
  return (1);
}
