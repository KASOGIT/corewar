/*
** my_strword.c for my_strword.c in /home/soto_a/rendu/lib_all
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Thu Oct  9 21:59:57 2014 adam kaso
** Last update Fri Dec  5 15:00:33 2014 Kaso Soto
*/

#include "my.h"

int	my_strword(char *str)
{
  int	i;
  int	w;

  i = 0;
  w = 0;
  while (str[i] != '\0')
    {
      if (my_char_is_print(str[i]) == 1)
	{
	  w++;
	  while (my_char_is_print(str[i]) == 1)
	    i++;
	}
      else
	i++;
    }
  return (w);
}
