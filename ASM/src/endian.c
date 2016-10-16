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

int	litle_to_big(int magic)
{
  magic = ((magic & 0x000000ff) << 24) | ((magic & 0x0000ff00) << 8)
    | ((magic & 0x00ff0000) >> 8) | ((magic & 0xff000000) >> 24);
  return (magic);
}
