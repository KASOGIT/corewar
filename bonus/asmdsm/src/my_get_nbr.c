/*
** my_get_nbr.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 04:11:35 2015 Manuel Trambert
** Last update Sat Apr 11 04:11:35 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my.h"

int	my_get_nbr(char *str)
{
  int	i;
  int	res;
  int	pow;
  int	e;

  if (str == NULL)
    return (0);
  i = my_strlen(str);
  e = (str[0] == '-' ? 1 : 0);
  res = 0;
  pow = 1;
  while (--i >= e)
    {
      res += (str[i] - 48) * pow;
      pow *= 10;
    }
  return ((str[0] == '-') ? (res * - 1) : (res));
}
