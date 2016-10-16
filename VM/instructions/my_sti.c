/*
** my_sti.c for  in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:49:33 2015 KASO soto
** Last update Sun Apr 12 17:16:55 2015 Kévin Julien
*/

#include "vm.h"

int		my_sti(t_corewar *corewar, t_list *champ)
{
  int		value_to_load;
  int		s;
  int		check_result;
  unsigned char	*byte_code;

  champ->champ.start_pc = champ->champ.pc;
  s = 0;
  incr_pc(champ, sizeof(char));
  byte_code = get_byte_code(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(char));
  value_to_load = get_values_instr(corewar, champ, byte_code, 10);
  s += get_values_instr_spec(corewar, champ, byte_code + 2, 10);
  check_result = s;
  s += get_values_instr_spec(corewar, champ, byte_code + 4, 10);
  if (s < check_result || check_result == -1 || value_to_load == -1)
    return (-1);
  if (s >= MEM_SIZE)
    return (my_put_error
	    ("sti : total index is larger than memory\n", 0, champ, 10));
  load_value_to_mem_adress_dir(corewar, value_to_load, s);
  champ->champ.delay = op_tab[10].nbr_cycles;
  return (0);
}
