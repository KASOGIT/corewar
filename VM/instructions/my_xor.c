/*
** my_xor.c for my_xor in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:47:27 2015 KASO soto
** Last update Sun Apr 12 13:14:49 2015 KASO soto
*/

#include "vm.h"

int		my_xor(t_corewar *corewar, t_list *champ)
{
  int           num_reg;
  int           values[2];
  unsigned char *byte_code;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  values[0] = get_values_instr(corewar, champ, byte_code, 7);
  values[1] = get_values_instr(corewar, champ, byte_code + 2, 7);
  if (values[0] == -1 || values[1] == -1)
    return (-1);
  if ((num_reg = corewar->mem[champ->champ.pc]) > 15)
    return (my_put_error("xor : wrong num reg\n", 0, champ, 7));
  champ->champ.reg[num_reg] = values[0] ^ values[1];
  incr_pc(champ, T_REG);
  champ->champ.carry = 1;
  champ->champ.delay = op_tab[7].nbr_cycles;
  return (0);
}
