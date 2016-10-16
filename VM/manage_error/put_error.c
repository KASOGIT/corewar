/*
** put_error.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/manage_error
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Apr 10 21:58:39 2015 KASO soto
** Last update Sun Apr 12 15:25:25 2015 KASO soto
*/

#include "vm.h"

int	my_put_error(char *explain, int mode, t_list *champ, int num_instr)
{
  write(2, explain, my_strlen(explain));
  if (mode)
    exit(EXIT_FAILURE);
  champ->champ.carry = 0;
  champ->champ.delay = op_tab[num_instr].nbr_cycles;
  return (-1);
}
