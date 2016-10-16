/*
** my_lldi.c for  in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:51:33 2015 KASO soto
** Last update Sun Apr 12 17:00:51 2015 Kévin Julien
*/

#include "vm.h"

int	my_get_value_ind_lldi(t_corewar *corewar, t_list *champ, int value)
{
  short	pos_short;

  pos_short = get_short_from_string(corewar->mem, champ->champ.pc);
  if (pos_short >= MEM_SIZE)
    return (my_put_error
	    ("set result lldi : pos 2 larger than memory\n", 0, champ, 13));
  load_value_to_mem_adress_ind(corewar, champ, value, pos_short);
  incr_pc(champ, IND_SIZE);
  return (0);
}

int	my_get_value_dir_lldi(t_corewar *corewar, t_list *champ, int value)
{
  int	pos_int;

  pos_int = get_int_from_string(corewar->mem, champ->champ.pc);
  if (pos_int >= MEM_SIZE)
    return (my_put_error
	    ("set result lldi : pos 1 larger than memory\n", 0, champ, 13));
  load_value_to_mem_adress_dir(corewar, value, pos_int);
  incr_pc(champ, DIR_SIZE);
  return (0);
}

int	set_result_lldi(t_corewar *corewar, t_list *champ,
			unsigned char *byte_code, int value)
{
  int   num_reg;

  if (byte_code[4] == 0 && byte_code[5] == 1)
    {
      if ((num_reg = corewar->mem[champ->champ.pc] - 1) > 15)
        return (my_put_error
		("set result lldi : wrong num reg\n", 0, champ, 13));
      champ->champ.reg[num_reg] = value;
      incr_pc(champ, sizeof(char));
    }
  else if (byte_code[4] == 1 && byte_code[5] == 0)
    return (my_get_value_dir_lldi(corewar, champ, value));
  else if (byte_code[4] == 1 && byte_code[5] == 1)
    return (my_get_value_ind_lldi(corewar, champ, value));
  else
    return (my_put_error("set result lldi : bad formed args\n", 0, champ, 13));
  return (0);
}

int		my_lldi(t_corewar *corewar, t_list *champ)
{
  unsigned char *byte_code;
  int           s;
  int           check_result;
  int           value;

  champ->champ.start_pc = champ->champ.pc;
  s = 0;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  s += get_values_instr_spec(corewar, champ, byte_code, 13);
  check_result = s;
  s += get_values_instr_spec(corewar, champ, byte_code + 2, 13);
  if (s < check_result || check_result == -1)
    return (-1);
  value = get_int_from_string(corewar->mem, get_pos(champ->champ.start_pc, s));
  incr_pc(champ, REG_SIZE);
  if (set_result_lldi(corewar, champ, byte_code, value) == -1)
    return (-1);
  champ->champ.delay = op_tab[13].nbr_cycles;
  champ->champ.carry = 1;
  return (0);
}
