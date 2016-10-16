/*
** act_on_memory.c for  in /home/soto_a/rendu/Corewar/act_for_instr
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Apr  5 15:14:28 2015 KASO soto
** Last update Sun Apr 12 18:32:59 2015 Kévin Julien
*/

#include "vm.h"

void		load_value_to_mem_adress_dir(t_corewar *corewar,
					     int value, int pos)
{
  int           i;
  unsigned char *str_value;

  i = 0;
  str_value = get_string_from_int(value);
  if (str_value)
    {
      while (i < 4)
	{
	  corewar->mem[pos] = str_value[i];
	  i++;
	  pos++;
	  if (pos == MEM_SIZE)
	    pos = 0;
	}
    }
}

void		load_value_to_mem_adress_ind(t_corewar *corewar, t_list *champ,
					     int value, short pos)
{
  int           i;
  unsigned char *str_value;
  int           new_pos;

  i = 0;
  str_value = get_string_from_int(value);
  new_pos = get_pos(champ->champ.start_pc, (int)pos);
  while (i < 4)
    {
      corewar->mem[new_pos] = str_value[i];
      new_pos++;
      i++;
      if (new_pos == MEM_SIZE)
	new_pos = 0;
    }
}
