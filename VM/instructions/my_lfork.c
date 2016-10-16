/*
** my_lfork.c for my_lfork in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:52:10 2015 KASO soto
** Last update Sun Apr 12 18:15:27 2015 Kévin Julien
*/

#include "vm.h"

int		my_lfork(t_corewar *corewar, t_list *champ)
{
  t_champ       new_champ;
  short           value;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  value = get_short_from_string(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(short));
  new_champ.pc = get_pos(champ->champ.start_pc, value);
  new_champ.alive = 0;
  new_champ.delay = 0;
  new_champ.prog_number = champ->champ.prog_number;
  new_champ.reg = copy_reg(champ->champ.reg);
  copy_prog_name(champ->champ.header.prog_name, &(new_champ.header));
  new_champ.carry = 0;
  my_put_in_list(&(corewar->champs), new_champ, 0);
  champ->champ.delay = op_tab[14].nbr_cycles;
  return (0);
}
