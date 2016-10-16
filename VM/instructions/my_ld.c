/*
** my_ld.c for  in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:20:57 2015 KASO soto
** Last update Sun Apr 12 18:53:06 2015 Kévin Julien
*/

#include "vm.h"

int	my_get_value_dir_ld(t_corewar *corewar, t_list *champ)
{
  int	value_int;
  int	num_reg;

  value_int = get_int_from_string(corewar->mem, champ->champ.pc);
  printf("Value de ld de merde -> %d pc = %d\n", value_int, champ->champ.pc);
  incr_pc(champ, sizeof(int));
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("ld : wrong num reg 1\n", 0, champ, 1));
  incr_pc(champ, T_REG);
  printf("le registre d emerde est = %d\n", num_reg);
  load_value_to_reg_dir(champ, value_int, num_reg);
  printf("pc apres le bug de merde = %d\n", champ->champ.pc);
  return (0);
}

int	my_get_value_ind_ld(t_corewar *corewar, t_list *champ)
{
  short	value_short;
  int	num_reg;

  value_short = get_short_from_string(corewar->mem, champ->champ.pc);
  incr_pc(champ, IND_SIZE);
  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("ld : wrong num reg 2\n", 0, champ, 1));
  incr_pc(champ, T_REG);
  load_value_to_reg_ind(corewar, champ, (int)value_short, num_reg);
  return (0);
}

int		my_ld(t_corewar *corewar, t_list *champ)
{
  unsigned char	*byte_code;

  champ->champ.start_pc = champ->champ.pc;
  champ->champ.delay = op_tab[1].nbr_cycles;
  champ->champ.carry = 1;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  if (byte_code[0] == 1 && byte_code[1] == 0)
    return (my_get_value_dir_ld(corewar, champ));
  else if (byte_code[0] == 1 && byte_code[1] == 1)
    return (my_get_value_ind_ld(corewar, champ));
  else
    return (my_put_error("ld : bad formed args\n", 0, champ, 1));
  champ->champ.carry = 1;
  champ->champ.delay = op_tab[1].nbr_cycles;
  return (0);
}
