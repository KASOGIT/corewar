/*
** my_strupcase.c for my_strupcase.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 18:21:35 2014 adam kaso
** Last update Sun Feb  1 22:22:21 2015 Kaso Soto
*/

#include "my.h"

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 32;
      i++;
    }
  return (str);
}
