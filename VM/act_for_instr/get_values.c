/*
** get_values.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/act_for_instr
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Apr 11 16:41:45 2015 KASO soto
** Last update Sun Apr 12 17:33:58 2015 Kévin Julien
*/

#include "vm.h"

int	get_value_reg(t_corewar *corewar, t_list *champ, int num_instr)
{
  int	value_int;
  int	num_reg;

  if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
    return (my_put_error("get_values : wrong num reg 1\n",
			 0, champ, num_instr));
  value_int = champ->champ.reg[num_reg];
  incr_pc(champ, T_REG);
  return (value_int);
}

int	get_value_dir(t_corewar *corewar, t_list *champ)
{
  int	value_int;

  value_int = get_int_from_string(corewar->mem, champ->champ.pc);
  incr_pc(champ, DIR_SIZE);
  return (value_int);
}

int	get_value_ind(t_corewar *corewar, t_list *champ)
{
  int   value_int;
  short value_short;

  value_short = get_short_from_string(corewar->mem, champ->champ.pc);
  value_int = get_int_from_string(corewar->mem,
				  get_pos(champ->champ.start_pc,
					  (int)value_short));
  incr_pc(champ, IND_SIZE);
  return (value_int);
}

int     get_values_instr(t_corewar *corewar, t_list *champ,
			 unsigned char *byte_code, int num_instr)
{
  if (byte_code[0] == 0 && byte_code[1] == 1)
    return (get_value_reg(corewar, champ, num_instr));
  else if (byte_code[0] == 1 && byte_code[1] == 0)
    return (get_value_dir(corewar, champ));
  else if (byte_code[0] == 1 && byte_code[1] == 1)
    return (get_value_ind(corewar, champ));
  else
    {
      printf("instru -> %d\n", num_instr);
    return (my_put_error
	    ("get_values : bad formed args\n", 0, champ, num_instr));
    }
  return (0);
}
