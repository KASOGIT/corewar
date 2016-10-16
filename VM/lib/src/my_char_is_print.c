/*
** my_char_is_print.c for my_char_is_print in /home/soto_a/my_funcs/header/lib/my
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Nov 24 09:10:26 2014 Kaso Soto
** Last update Fri Dec  5 14:46:58 2014 Kaso Soto
*/

#include "my.h"

int     my_char_is_print(char c)
{
  if (!(c > 32 && c <= 126))
    return (0);
  else
    return (1);
}
