/*
** my_strcmp.c for my_strcmp.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 15:47:43 2014 adam kaso
** Last update Mon Jan 19 18:45:48 2015 Kaso Soto
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i != n)
    {
      if (s1[i] != s2[i])
	return ((s1[i] < s2[i]) ? -1 : 1);
      i++;
    }
  return (0);
}
