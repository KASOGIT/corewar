/*
** my_strcpy.c for my_strcpy.c in /home/soto_a/rendu/Piscine_C_J06/ex_01
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 09:47:45 2014 adam kaso
** Last update Fri Dec  5 14:54:48 2014 Kaso Soto
*/

#include "my.h"

char	*my_strcpy(char *src, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      src[i] = str[i];
      i++;
    }
  src[i] = '\0';
  return (src);
}
