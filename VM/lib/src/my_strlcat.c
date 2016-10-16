/*
** my_strlcat.c for my_strlcat.c in /home/soto_a/rendu/Piscine_C_J07/ex_05
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Oct  8 10:29:44 2014 adam kaso
** Last update Fri Dec  5 14:57:06 2014 Kaso Soto
*/

#include "my.h"

int	my_strlcat(char *dest, char *src, int size)
{
  if (size < my_strlen(dest))
    return (my_strlen(dest) - (my_strlen(dest) - size) + my_strlen(src));
  else
    return (size + my_strlen(src));
}
