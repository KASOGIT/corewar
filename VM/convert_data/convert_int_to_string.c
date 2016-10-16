/*
** convert_int_to_string.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/convert_data
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  8 12:58:58 2015 KASO soto
** Last update Wed Apr  8 13:03:52 2015 KASO soto
*/

#include "vm.h"

unsigned char	*get_string_from_int(int value)
{
  unsigned char	*str_value;

  if ((str_value = malloc(sizeof(unsigned char) * 4)) == NULL)
    exit(EXIT_FAILURE);
  str_value[0] = (value >> 24) & 0xFF;
  str_value[1] = (value >> 16) & 0xFF;
  str_value[2] = (value >> 8) & 0xFF;
  str_value[3] = (value >> 0) & 0xFF;
  return (str_value);
}
