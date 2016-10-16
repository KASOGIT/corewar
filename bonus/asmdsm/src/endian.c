/*
** endian.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 04:23:44 2015 Manuel Trambert
** Last update Sat Apr 11 04:23:49 2015 Manuel Trambert
*/

#include "my.h"

int		litle_endian()
{
  unsigned int	x;

  x = 1;
  return ((int) (((char *)&x)[0]));
}

int	litle_to_big(int x)
{
  x = ((x >> 24) & 0xffL) | ((x >> 8) & 0xff00L)
    | ((x << 8) & 0xff0000L) | ((x << 24) & 0xff000000L);
  return (x);
}
