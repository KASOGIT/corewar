/*
** my_strdup.c for my_strdup.c in /home/soto_a/rendu/Piscine_C_J08
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Oct  8 22:21:05 2014 adam kaso
** Last update Tue Dec 23 17:05:27 2014 Kaso Soto
*/

#include "my.h"

char	*my_strdup(char *src)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
