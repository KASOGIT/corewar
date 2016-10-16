/*
** convert_string_to_int.c for convert_string_to_int in /home/soto_a/rendu/Corewar/convert_data
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Thu Apr  2 16:12:40 2015 KASO soto
** Last update Sun Apr 12 18:44:09 2015 Kévin Julien
*/

#include "vm.h"

unsigned char		*get_str_in_mem(unsigned char *mem, int pc, int size)
{
  int			i;
  unsigned char		*geter;

  i = size - 1;
  if ((geter = malloc(sizeof(unsigned char) * size)) == NULL)
    exit(EXIT_FAILURE);
  while (i != -1)
    {
      geter[i] = mem[pc];
      pc++;
      i--;
      if (pc == MEM_SIZE)
	pc = 0;
    }
  return (geter);
}

int		get_int_from_string(unsigned char *mem, int pc)
{
  unsigned char	*get_str;
  int		value;

  get_str = get_str_in_mem(mem, pc, DIR_SIZE);
  if (get_str)
    {
      value = *((int *)&get_str[0]);
      free(get_str);
      return (value);
    }
  return (0);
}
