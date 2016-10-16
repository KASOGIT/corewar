/*
** convert_string_to_short.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/convert_data
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Apr  7 18:07:14 2015 KASO soto
** Last update Sat Apr 11 23:45:46 2015 KASO soto
*/

#include "vm.h"

short		get_short_from_string(unsigned char *mem, int pc)
{
  unsigned char	*get_str;
  short		value;

  get_str = get_str_in_mem(mem, pc, IND_SIZE);
  value = *((short *)&get_str[0]);
  return (value);
}
