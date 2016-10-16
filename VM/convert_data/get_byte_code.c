/*
** get_byte_code.c for  in /home/soto_a/rendu/Corewar/convert_data
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Apr  3 15:41:58 2015 KASO soto
** Last update Sun Apr 12 15:10:52 2015 KASO soto
*/

#include "vm.h"

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
