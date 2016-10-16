/*
** my_lld.c for my_lld in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:50:49 2015 KASO soto
** Last update Sun Apr 12 17:12:11 2015 Kévin Julien
*/

#include "vm.h"

void    load_value_to_reg_ind_lld(t_corewar *corewar,
				  t_list *champ, int pos, int num_reg)
{
  int   final_value;

  final_value = get_int_from_string
    (corewar->mem, get_pos(champ->champ.start_pc, pos));
  champ->champ.reg[num_reg] = final_value;
}

int	my_get_value_ind_lld(t_corewar *corewar, t_list *champ)
{
  short	value_short;
  int	num_reg;

  value_short = get_short_from_string(corewar->mem, champ->champ.pc);
  if (value_short >= MEM_SIZE)
    return (my_put_error("lld : pos larger than memory\n", 0, champ, 12));
  incr_pc(champ, IND_SIZE);
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("lld : wrong num  reg 2\n", 0, champ, 12));
  incr_pc(champ, T_REG);
  load_value_to_reg_ind_lld(corewar, champ, (int)value_short, num_reg);
  return (0);
}

int		my_lld(t_corewar *corewar, t_list *champ)
{
  int           value_int;
  int           num_reg;
  unsigned char *byte_code;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  if (byte_code[0] == 1 && byte_code[1] == 0)
    {
      value_int = get_int_from_string(corewar->mem, champ->champ.pc);
      incr_pc(champ, DIR_SIZE);
      if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
	return (my_put_error("lld : wrong num  reg 1\n", 0, champ, 12));
      incr_pc(champ, T_REG);
      load_value_to_reg_dir(champ, value_int, num_reg);
    }
  else if (byte_code[0] == 1 && byte_code[1] == 1)
    return (my_get_value_ind_lld(corewar, champ));
  else
    return (my_put_error("lld : bad formed args\n", 0, champ, 12));
  champ->champ.delay = op_tab[12].nbr_cycles;
  champ->champ.carry = 1;
  return (0);
}
