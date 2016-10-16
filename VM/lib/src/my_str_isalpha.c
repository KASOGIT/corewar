/*
** my_str_isalpha.c for my_str_isalpha.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 22:51:49 2014 adam kaso
** Last update Sun Mar  8 19:03:45 2015 KASO soto
*/

#include "my.h"

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'a' && str[i] <= 'z')
	  && !(str[i] >= 'A' && str[i] <= 'Z'))
     	return (0);
      i++;
    }
  return (1);
}
