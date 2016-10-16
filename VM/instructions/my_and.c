/*
** my_and.c for my_and in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:46:17 2015 KASO soto
** Last update Sun Apr 12 13:13:34 2015 KASO soto
*/

#include "vm.h"

int		my_and(t_corewar *corewar, t_list *champ)
{
  int		num_reg;
  int		values[2];
  unsigned char	*byte_code;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  values[0] = get_values_instr(corewar, champ, byte_code, 5);
  values[1] = get_values_instr(corewar, champ, byte_code + 2, 5);
  if (values[0] == -1 || values[1] == -1)
    return (-1);
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("and : wrong num reg \n", 0, champ, 5));
  champ->champ.reg[num_reg] = values[0] & values[1];
  incr_pc(champ, T_REG);
  champ->champ.carry = 1;
  champ->champ.delay = op_tab[5].nbr_cycles;
  return (0);
}
