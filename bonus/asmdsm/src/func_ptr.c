/*
** func_ptr.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 03:50:03 2015 Manuel Trambert
** Last update Sun Apr 12 17:25:15 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my.h"

t_dsm_func	g_dsm_func[] =
  {
    {0x01, "live", 0, &print_ind},
    {0x02, "ld", 2, &get_size_oct},
    {0x03, "st", 2, &get_size_oct},
    {0x04, "add", 3, &get_size_oct},
    {0x05, "sub", 3, &get_size_oct},
    {0x06, "and", 3, &get_size_oct},
    {0x07, "or", 3, &get_size_oct},
    {0x08, "xor", 3, &get_size_oct},
    {0x09, "zjmp", -1, &print_dir},
    {0x10, "aff", -1, &print_dir},
    {0x0a, "ldi", -2, &get_size_ldi},
    {0x0b, "sti", -2, &get_size_sti},
    {0x0c, "fork", -1, &print_dir},
    {0x0d, "lld", 1, &get_size_oct},
    {0x0e, "lldi", 2, &get_size_oct},
    {0x0f, "lfork", -1, &print_dir},
    {0, NULL, 0, NULL}
  };

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
