/*
** parsing_champ_load_champ_memory.c for load_champ_memory in /home/soto_a/rendu/Corewar/linked_list
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Mar 31 10:55:52 2015 KASO soto
** Last update Sun Apr 12 16:24:17 2015 KASO soto
*/

#include "vm.h"

void	init_mem(t_corewar *corewar)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      corewar->mem[i] = 0;
      i++;
    }
}

void	init_var_load_memory(t_list *tmp)
{
  tmp->champ.alive = 0;
  tmp->champ.carry = 0;
  tmp->champ.delay = 0;
}

void		load_champ_in_memory(t_corewar *corewar)
{
  int		i;
  int		a;
  int		forward;
  t_list	*tmp;

  tmp = corewar->champs->next;
  init_mem(corewar);
  while (tmp != corewar->champs)
    {
      forward = 0;
      tmp->champ.reg[0] = tmp->champ.prog_number;
      tmp->champ.pc = tmp->champ.mem_size[0];
      i = tmp->champ.mem_size[0];
      a = i;
      while (i < (tmp->champ.mem_size[0] + tmp->champ.header.prog_size))
	{
	  corewar->mem[a++] = tmp->champ.prog[forward++];
	  if (a >= MEM_SIZE)
	    a = 0;
	  i++;
	}
      tmp = tmp->next;
    }
}
