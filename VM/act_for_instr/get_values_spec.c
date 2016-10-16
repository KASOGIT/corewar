/*
** get_values_spec.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/act_for_instr
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Apr 12 15:08:00 2015 KASO soto
** Last update Sun Apr 12 17:43:28 2015 Kévin Julien
*/

#include "vm.h"

int     get_value_dir_spec(t_corewar *corewar, t_list *champ)
{
  short value_short;

  value_short = get_short_from_string(corewar->mem, champ->champ.pc);
  incr_pc(champ, IND_SIZE);
  return ((int)value_short);
}

int     get_value_ind_spec(t_corewar *corewar, t_list *champ)
{
  short value_short;

  value_short = get_short_from_string(corewar->mem, champ->champ.pc);
  value_short = get_short_from_string(corewar->mem,
                                      get_pos(champ->champ.start_pc,
					      (int)value_short));
  incr_pc(champ, IND_SIZE);
  return ((int)value_short);
}

int     get_values_instr_spec(t_corewar *corewar, t_list *champ,
			      unsigned char *byte_code, int num_instr)
{
  if (byte_code[0] == 0 && byte_code[1] == 1)
    return (get_value_reg(corewar, champ, num_instr));
  else if (byte_code[0] == 1 && byte_code[1] == 0)
    return (get_value_dir_spec(corewar, champ));
  else if (byte_code[0] == 1 && byte_code[1] == 1)
    return (get_value_ind_spec(corewar, champ));
  else
    {
      printf("instru -> %d\n", num_instr);
      return (my_put_error("get_values : bad formed args\n", 0, champ, num_instr));
    }
  return (0);
}
