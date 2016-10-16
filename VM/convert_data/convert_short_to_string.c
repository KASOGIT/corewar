/*
** convert_short_to_string.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/convert_data
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  8 12:58:38 2015 KASO soto
** Last update Wed Apr  8 13:05:47 2015 KASO soto
*/

#include "vm.h"

unsigned char	*get_string_from_short(short value)
{
  unsigned char	*str_value;

  if ((str_value = malloc(sizeof(unsigned char) * 2)) == NULL)
    exit(EXIT_FAILURE);
  str_value[0] = (value >> 8) & 0xFF;
  str_value[1] = (value >> 0) & 0xFF;
  return (str_value);
}
