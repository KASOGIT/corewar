/*
** my_strncat.c for my_strncat.c in /home/soto_a/rendu/Piscine_C_J07
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 14:12:33 2014 adam kaso
** Last update Fri Dec  5 14:58:02 2014 Kaso Soto
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (j < my_strlen(src) && j < nb)
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return (dest);
}
