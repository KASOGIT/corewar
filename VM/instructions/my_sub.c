/*
** my_sub.c for my_sub in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:45:43 2015 KASO soto
** Last update Sat Apr 11 17:18:54 2015 KASO soto
*/

#include "vm.h"

int		my_sub(t_corewar *corewar, t_list *champ)
{
  int		value;
  int		num_reg;

  incr_pc(champ, sizeof(char));
  incr_pc(champ, sizeof(char));
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("sub : Wrong num reg 1\n", 0, champ, 4));
  value = champ->champ.reg[num_reg];
  incr_pc(champ, T_REG);
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("sub : Wrong num reg 2\n", 0, champ, 4));
  value -= champ->champ.reg[num_reg];
  incr_pc(champ, T_REG);
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("sub : Wrong num reg 3\n", 0, champ, 4));
  champ->champ.reg[num_reg] = value;
  incr_pc(champ, T_REG);
  champ->champ.delay = op_tab[4].nbr_cycles;
  champ->champ.carry = 1;
  return (0);
}
