/*
** my_strupcase.c for my_strupcase.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 18:21:35 2014 adam kaso
** Last update Fri Dec  5 14:57:29 2014 Kaso Soto
*/

#include "my.h"

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] += 32;
      i++;
    }
  return (str);
}
