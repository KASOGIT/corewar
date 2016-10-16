/*
** my_revstr.c for my_revstr.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 11:37:42 2014 adam kaso
** Last update Fri Dec  5 14:51:47 2014 Kaso Soto
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  char	c;

  i = 0;
  c = 0;
  while (i < my_strlen(str) / 2)
    {
      c = str[my_strlen(str) - i - 1];
      str[my_strlen(str) - i - 1] = str[i];
      str[i] = c;
      i++;
    }
  return (str);
}
