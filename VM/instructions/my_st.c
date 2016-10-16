/*
** my_st.c for  in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:23:30 2015 KASO soto
** Last update Sun Apr 12 17:16:11 2015 Kévin Julien
*/

#include "vm.h"

void	my_set_value_st(t_corewar *corewar, t_list *champ, int value_reg,
			int bool)
{
  int	pos_int;
  short	pos_short;

  if (bool == 0)
    {
      pos_int = get_int_from_string(corewar->mem, champ->champ.pc);
      incr_pc(champ, DIR_SIZE);
      load_value_to_mem_adress_dir(corewar, value_reg, pos_int);
    }
  else if (bool == 1)
    {
      pos_short = get_short_from_string(corewar->mem, champ->champ.pc);
      incr_pc(champ, IND_SIZE);
      load_value_to_mem_adress_ind(corewar, champ, value_reg, pos_short);
    }
}

int	my_get_value_reg_st(t_corewar *corewar, t_list *champ, int value_reg)
{
  int	pos_int;

  pos_int = corewar->mem[champ->champ.pc] - 1;
  incr_pc(champ, sizeof(char));
  if (pos_int > 15)
    return (my_put_error("st : num reg2 wrong value\n", 0, champ, 2));
  champ->champ.reg[pos_int] = value_reg;
  return (0);
}

int		my_st(t_corewar *corewar, t_list *champ)
{
  int		value_reg;
  int		num_reg;
  unsigned char	*byte_code;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  num_reg = corewar->mem[champ->champ.pc] - 1;
  if (num_reg > 15)
    return (my_put_error("st : num reg1 wrong value\n", 0, champ, 2));
  value_reg = champ->champ.reg[num_reg];
  incr_pc(champ, T_REG);
  if (byte_code[2] == 1 && byte_code[3] == 0)
    my_set_value_st(corewar, champ, value_reg, 0);
  else if (byte_code[2] ==  1 && byte_code[3] == 1)
    my_set_value_st(corewar, champ, value_reg, 1);
  else if (byte_code[2] == 0 && byte_code[3] == 1)
    return (my_get_value_reg_st(corewar, champ, value_reg));
  else
    return (my_put_error("st : bad formed args\n", 0, champ, 2));
  champ->champ.delay = op_tab[2].nbr_cycles;
  return (0);
}
