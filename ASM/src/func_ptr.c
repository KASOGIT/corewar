/*
** func_ptr.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 03:50:03 2015 Manuel Trambert
** Last update Sat Apr 11 03:50:03 2015 Manuel Trambert
*/

#include "my.h"

t_type_func	g_type_func[] =
  {
    {1, &check_reg},
    {2, &check_dir},
    {3, &check_reg_dir},
    {4, &check_ind},
    {5, &check_reg_ind},
    {6, &check_dir_ind},
    {7, &check_everytype},
    {0, NULL}
  };

t_name_func	g_name_func[] =
  {
    {"live", &write_live},
    {"add", &write_add},
    {"sub", &write_sub},
    {"and", &write_and},
    {"or", &write_or},
    {"xor", &write_xor},
    {"zjmp", &write_zjmp},
    {"ldi", &write_ldi},
    {"sti", &write_sti},
    {"fork", &write_fork},
    {"lldi", &write_lldi},
    {"lld", &write_lld},
    {"lfork", &write_lfork},
    {"aff", &write_aff},
    {"st", &write_st},
    {"ld", &write_ld},
    {NULL, NULL}
  };

t_cmd		g_cmd[] =
  {
    {"live", 4},
    {"add", 4},
    {"sti", -1},
    {"sub", 4},
    {"zjmp", 2},
    {"lfork", 2},
    {"fork", 2},
    {"aff", 3},
    {"ldi", -2},
    {NULL, 0}
  };
