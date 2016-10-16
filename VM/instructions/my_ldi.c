/*
** my_ldi.c for  in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:48:58 2015 KASO soto
** Last update Sun Apr 12 19:43:04 2015 Manuel Trambert
*/

#include "vm.h"

int	my_get_value_dir_ldi(t_corewar *corewar, t_list *champ, int value)
{
  int	pos_int;

  pos_int = get_int_from_string(corewar->mem, champ->champ.pc);
  if (pos_int >= MEM_SIZE)
    return (my_put_error
	    ("set result ldi : pos 1 larger than memory\n", 0, champ, 9));
  load_value_to_mem_adress_dir(corewar, value, pos_int);
  incr_pc(champ, DIR_SIZE);
  return (0);
}

int	set_result_ldi(t_corewar *corewar, t_list *champ,
		       unsigned char *byte_code, int value)
{
  short	pos_short;
  int	num_reg;

  if (byte_code[4] == 0 && byte_code[5] == 1)
    {
      if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
	return (my_put_error("set result ldi : wrong num reg\n", 0, champ, 9));
      champ->champ.reg[num_reg] = value;
      incr_pc(champ, sizeof(char));
    }
  else if (byte_code[4] == 1 && byte_code[5] == 0)
    return (my_get_value_dir_ldi(corewar, champ, value));
  else if (byte_code[4] == 1 && byte_code[5] == 1)
    {
      pos_short = get_short_from_string(corewar->mem, champ->champ.pc);
      if (pos_short >= MEM_SIZE)
	return (my_put_error
		("set result ldi : pos 2 larger than memory\n", 0, champ, 9));
      load_value_to_mem_adress_ind(corewar, champ, value, pos_short);
      incr_pc(champ, IND_SIZE);
    }
  else
    return (my_put_error("set result ldi : bad formed args\n", 0, champ, 9));
  return (0);
}

int		my_ldi(t_corewar *corewar, t_list *champ)
{
  unsigned char	*byte_code;
  int		s;
  int		check_result;
  int		value;

  champ->champ.start_pc = champ->champ.pc;
  s = 0;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  s += get_values_instr_spec(corewar, champ, byte_code, 9);
  printf("cod -> %d %d %d %d %d %d\n", byte_code[0], byte_code[1], byte_code[2], byte_code[3], byte_code[4], byte_code[5]);
  check_result = s;
  s += get_values_instr_spec(corewar, champ, byte_code + 2, 9);
  if (s < check_result || check_result == -1)
    return (-1);
  value = get_int_from_string(corewar->mem, get_pos(champ->champ.start_pc,
						    s % IDX_MOD));
  incr_pc(champ, REG_SIZE);
  if (set_result_ldi(corewar, champ, byte_code, value) == -1)
    return (-1);
  champ->champ.delay = op_tab[9].nbr_cycles;
  champ->champ.carry = 1;
  return (0);
}
