/*
** act_on_reg.c for  in /home/soto_a/rendu/Corewar/act_for_instr
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Apr  3 19:09:15 2015 KASO soto
** Last update Sun Apr 12 14:25:18 2015 KASO soto
*/

#include "vm.h"

void	load_value_to_reg_ind(t_corewar *corewar, t_list *champ,
			      int pos, int num_reg)
{
  int   final_value;

  final_value = get_int_from_string(corewar->mem,
				    get_pos(champ->champ.start_pc,
					    (pos % IDX_MOD)));
  champ->champ.reg[num_reg] = final_value;
}

void    load_value_to_reg_dir(t_list *champ, int value, int num_reg)
{
  champ->champ.reg[num_reg] = value;
}
