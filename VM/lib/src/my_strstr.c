/*
** my_strstr.c for my_strstr.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Oct  6 12:49:23 2014 adam kaso
** Last update Fri Dec  5 14:59:13 2014 Kaso Soto
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  while (*str)
    {
      if (my_strncmp(str, to_find, my_strlen(to_find)) == 0)
	return str;
      str++;
    }
  return (0);
}
