/*
** game.c for game in /home/soto_a/rendu/Corewar/GAME
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar 30 16:16:28 2015 KASO soto
** Last update Sun Oct 16 15:57:42 2016 
*/

#include "vm.h"

int	check_and_run(t_corewar *corewar, t_list *tmp, int i)
{
  if (g_tab_func[i].id_cmd == corewar->mem[tmp->champ.pc])
    {
      printf("cmd -> %s\n", op_tab[i].mnemonique);
      g_tab_func[i].ptr_func(corewar, tmp);
      return (0);
    }
  return (1);
}

void		run_instructions(t_corewar *corewar)
{
  int		i;
  int		bool;
  t_list	*tmp;

  tmp = corewar->champs->next;
  while (tmp != corewar->champs)
    {
      i = 0;
      bool = 1;
      if (tmp->champ.delay == 0)
	{
	  while (i < NBR_INSTR && bool)
	    {
	      bool = check_and_run(corewar, tmp, i);
	      i++;
	    }
	  if (bool == 1)
	    incr_pc(tmp, sizeof(char));
	}
      else
	tmp->champ.delay--;
      tmp = tmp->next;
    }
}

int	init_var_game(int *cycle_bef_end, int *delta_count)
{
  *cycle_bef_end = 0;
  *delta_count = 0;
  return (0);
}

void	check_nbr_live_and_set_delta(t_corewar *corewar, int nb_in_live,
				     int *delta_count, int *to_die)
{
  if (corewar->nb_live == NBR_LIVE
      && nb_in_live == count_in_live(&(corewar->champs)))
    {
      *delta_count += CYCLE_DELTA;
      *to_die -= *delta_count;
      corewar->nb_live = 0;
    }
  else if (corewar->nb_live == NBR_LIVE)
    corewar->nb_live = 0;
}

void	run_game(t_corewar *corewar)
{
  int	cycle_bef_end;
  int	nb_in_live;
  int	to_die;
  int	cycle_count;
  int	delta_count;

  corewar->nb_live = init_var_game(&cycle_bef_end, &delta_count);
  while (cycle_bef_end == 0 || is_alive(&(corewar->champs)))
    {
      nb_in_live = cycle_bef_end == 0 ? corewar->nb_champ :
	count_in_live(&(corewar->champs));
      reset_alive(&(corewar->champs));
      cycle_count = 0;
      to_die = CYCLE_TO_DIE - delta_count;
      while (cycle_count < to_die && cycle_bef_end < corewar->nb_cycle_bef_end)
	{
	  run_instructions(corewar);
	  check_nbr_live_and_set_delta(corewar, nb_in_live, &delta_count, &to_die);
	  incr_var_game(&cycle_bef_end, &cycle_count);
	}
      if (cycle_bef_end >= corewar->nb_cycle_bef_end)
	dump_memory(corewar->mem);
      delete_dead_champ(&(corewar->champs));
    }
  who_win(&(corewar->champs));
}
