/*
** my_strcapitalize.c for my_strcapitalize.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 19:17:08 2014 adam kaso
** Last update Fri Dec  5 14:54:05 2014 Kaso Soto
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  str[i] -= 32;
	  i++;
	  while (str[i] >= 'a' && str[i] <= 'z')
	    i++;
	}
      else if (str[i] >= '0' && str[i] <= '9')
	{
	  i++;
	  while (str[i] >= '0' && str[i] <= '9')
	    i++;
	  if (str[i] >= 'a' && str[i] <= 'z')
	    while (str[i] >= 'a' && str[i] <= 'z')
	      i++;
	}
      i++;
    }
  return (str);
}
