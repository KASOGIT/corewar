/*
** my_strncpy.c for my_strncpy.c in /home/soto_a/rendu/Piscine_C_J06/ex_01
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 10:59:21 2014 adam kaso
** Last update Fri Dec  5 14:58:53 2014 Kaso Soto
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
