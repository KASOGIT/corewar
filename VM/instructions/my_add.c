/*
** my_add.c for my_add in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:24:06 2015 KASO soto
** Last update Sat Apr 11 17:09:56 2015 KASO soto
*/

#include "vm.h"

int		my_add(t_corewar *corewar, t_list *champ)
{
  int		value;
  int		num_reg;

  incr_pc(champ, sizeof(char));
  incr_pc(champ, sizeof(char));
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("my add : Wrong num reg 1\n", 0, champ, 3));
  value = champ->champ.reg[num_reg];
  incr_pc(champ, T_REG);
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("my add : Wrong num reg 2\n", 0, champ, 3));
  value += champ->champ.reg[num_reg];
  incr_pc(champ, T_REG);
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("my add : Wrong num reg 3\n", 0, champ, 3));
  champ->champ.reg[num_reg] = value;
  incr_pc(champ, T_REG);
  champ->champ.delay = op_tab[3].nbr_cycles;
  champ->champ.carry = 1;
  return (0);
}
