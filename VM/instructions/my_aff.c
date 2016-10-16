/*
** my_aff.c for my_add in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:52:46 2015 KASO soto
** Last update Sun Apr 12 13:24:13 2015 KASO soto
*/

#include "vm.h"

int		my_aff(t_corewar *corewar, t_list *champ)
{
  int		value;
  int		num_reg;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  incr_pc(champ, sizeof(char));
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("aff: wrong num reg\n", 0, champ, 15));
  value = champ->champ.reg[num_reg];
  my_putchar(value % 256);
  incr_pc(champ, T_REG);
  champ->champ.delay = op_tab[15].nbr_cycles;
  champ->champ.carry = 1;
  return (0);
}
