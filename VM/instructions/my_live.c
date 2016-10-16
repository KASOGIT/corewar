/*
** my_live.c for my_live in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:10:58 2015 KASO soto
** Last update Sun Apr 12 16:49:19 2015 Kévin Julien
*/

#include "vm.h"

void		my_put_live(t_list *tmp)
{
  my_putstr("le joueur ");
  my_put_nbr(tmp->champ.prog_number);
  my_putchar('(');
  my_putstr(tmp->champ.header.prog_name);
  my_putstr(") est en vie\n");
}

int		my_live(t_corewar *corewar, t_list *champ)
{
  t_list	*tmp;
  int		bool;
  int		num_champ;

  bool = 1;
  incr_pc(champ, sizeof(char));
  corewar->nb_live++;
  tmp = corewar->champs->next;
  num_champ = get_int_from_string(corewar->mem, champ->champ.pc);
  while (bool && tmp != corewar->champs)
    {
      if (tmp->champ.prog_number == num_champ)
	{
	  bool = 0;
	  my_put_live(tmp);
	  tmp->champ.alive = 1;
	}
      tmp = tmp->next;
    }
  incr_pc(champ, sizeof(int));
  champ->champ.delay = op_tab[0].nbr_cycles;
  return (0);
}
