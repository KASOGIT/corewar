/*
** convert_endian.c for convert_endian in /home/soto_a/rendu/Corewar/endian
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Mar 29 15:28:05 2015 KASO soto
** Last update Sun Apr 12 15:11:49 2015 KASO soto
*/

#include "vm.h"

int             litle_endian()
{
  unsigned int  x;

  x = 1;
  return ((int) (((char *)&x)[0]));
}

int     litle_to_big(int x)
{
  x = ((x & 0x000000ff) << 24) | ((x & 0x0000ff00) << 8)
    | ((x & 0x00ff0000) >> 8) | ((x & 0xff000000) >> 24);
  return (x);
}

short	litle_to_big_short(short val)
{
  return ((val << 8) | ((val >> 8) & 0xFF));
}
