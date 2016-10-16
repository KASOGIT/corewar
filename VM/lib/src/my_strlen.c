/*
** my_strlen.c for my_strlen.c in /home/soto_a/rendu/Piscine_C_J04
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Thu Oct  2 13:39:44 2014 adam kaso
** Last update Fri Dec  5 14:57:16 2014 Kaso Soto
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
