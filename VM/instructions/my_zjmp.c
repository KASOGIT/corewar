/*
** my_zjmp.c for my_zjmp in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:48:21 2015 KASO soto
** Last update Sun Apr 12 18:15:53 2015 Kévin Julien
*/

#include "vm.h"

int	my_zjmp(t_corewar *corewar, t_list *champ)
{
  short	value_short;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  value_short = get_short_from_string(corewar->mem, champ->champ.pc);
  if (value_short >= MEM_SIZE)
    return (my_put_error("zjmp : pos larger than memory size\n", 0, champ, 8));
  incr_pc(champ, IND_SIZE);
  if (champ->champ.carry == 1)
    champ->champ.pc = get_pos(champ->champ.start_pc,
			      (int)value_short % IDX_MOD);
  champ->champ.delay = op_tab[8].nbr_cycles;
  return (0);
}
