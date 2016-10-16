/*
** read.c for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 17:20:53 2015 Manuel Trambert
** Last update Sun Apr 12 17:20:53 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my.h"

unsigned char	*get_byte_code(unsigned char *mem, int pc)
{
  int		i;
  int		j;
  unsigned char	*byte_code;
  unsigned char	byte_code_c;

  i = 7;
  j = 0;
  byte_code_c = mem[pc];
  if ((byte_code = malloc(sizeof(unsigned char) * 8)) == NULL)
    exit(EXIT_FAILURE);
  while (i != -1)
    {
      byte_code[j] = (byte_code_c >> i) & 1;
      i--;
      j++;
    }
  return (byte_code);
}
