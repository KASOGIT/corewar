/*
** my_strcat.c for my_strcat.c in /home/soto_a/rendu/Piscine_C_J07
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 14:12:33 2014 adam kaso
** Last update Sun Mar  8 19:19:07 2015 KASO soto
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	a;
  int	size_a;
  int	size_b;
  char	*new_str;

  i = -1;
  size_a = my_strlen(dest);
  size_b = my_strlen(src);
  if ((new_str = malloc(sizeof(char) * (size_a + size_b + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (dest[++i])
    new_str[i] = dest[i];
  a = i;
  i = 0;
  while (src[i])
    {
      new_str[a] = src[i];
      a++;
      i++;
    }
  new_str[a] = '\0';
  return (new_str);
}
