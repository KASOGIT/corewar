/*
** tab_ptr_func.c for tab_ptr_func in /home/soto_a/rendu/Corewar
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 11:44:31 2015 KASO soto
** Last update Wed Apr  1 16:25:27 2015 KASO soto
*/

#include "vm.h"

t_ptr_func	g_tab_func[] =
{
  {0x01, &my_live},
  {0x02, &my_ld},
  {0x03, &my_st},
  {0x04, &my_add},
  {0x05, &my_sub},
  {0x06, &my_and},
  {0x07, &my_or},
  {0x08, &my_xor},
  {0x09, &my_zjmp},
  {0x0a, &my_ldi},
  {0x0b, &my_sti},
  {0x0c, &my_fork},
  {0x0d, &my_lld},
  {0x0e, &my_lldi},
  {0x0f, &my_lfork},
  {0x10, &my_aff},
  {0, NULL}
};
