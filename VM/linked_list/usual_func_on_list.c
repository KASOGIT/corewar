/*
** usual_func_on_list.c for usual_func in /home/soto_a/rendu/CPE_2014_Pushswap
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Dec  2 15:55:03 2014 Kaso Soto
** Last update Sun Apr 12 15:23:46 2015 KASO soto
*/

#include "vm.h"

void	my_init_list(t_list **list)
{
  if (((*list) = malloc(sizeof(t_list))) == NULL)
    my_put_error("Malloc fail\n", 1, NULL, 0);
  (*list)->prev = *list;
  (*list)->next = *list;
}

void	set_memory_champ_default(t_parsing_arg *pars)
{
  int	*tmp_mem;

  tmp_mem = init_mem_per_champ(pars->nb_champ, &(pars->start));
  pars->champ.mem_size[0] = tmp_mem[0];
  pars->champ.mem_size[1] = tmp_mem[1];
  free(tmp_mem);
}

void		my_create_list(t_corewar *corewar, char **av)
{
  t_parsing_arg	pars;

  init_var_pars(&pars, av);
  corewar->nb_champ = count_nb_champ(av);
  while (av[pars.i])
    {
      pars.count_param = 1;
      check_arg_and_set_value(av + pars.i, &pars);
      if (pars.count_param == 1)
	{
	  if (pars.champ.mem_size[0] == -1)
	    set_memory_champ_default(&pars);
	  read_and_check_info_champ(&(pars.champ), av[pars.i]);
	  my_put_in_list(&(corewar->champs), pars.champ, 0);
	  reset_var_pars(&pars);
	}
      else
	pars.i += pars.count_param;
    }
  control_champ_load(&(corewar->champs), pars.nb_champ);
  load_champ_in_memory(corewar);
}

void		my_put_in_list(t_list **list, t_champ champ, int choice)
{
  t_list        *new_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    my_put_error("Malloc fail\n", 1, NULL, 0);
  if (choice == 0)
    {
      new_elem->prev = (*list)->prev;
      new_elem->next = (*list);
      (*list)->prev->next = new_elem;
      (*list)->prev = new_elem;
      new_elem->champ = champ;
    }
  else
    {
      new_elem->champ = champ;
      new_elem->prev = (*list);
      new_elem->next = (*list)->next;
      (*list)->next->prev = new_elem;
      (*list)->next = new_elem;
    }
}

int		my_size_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list->next;
  i = 0;
  while (tmp != list)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}
