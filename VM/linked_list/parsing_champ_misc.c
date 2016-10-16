/*
** parsing_champ_misc.c for misc in /home/soto_a/rendu/Corewar/linked_list
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Mar 28 22:11:58 2015 KASO soto
** Last update Sun Apr 12 11:42:17 2015 KASO soto
*/

#include "vm.h"

int	count_nb_champ(char **av)
{
  int   i;
  int   count;

  i = 0;
  count = 0;
  av[-1] = NULL;
  while (av[i])
    {
      if (av[i][0] != '-'
	  && av[i][1] != 'n' && av[i][1] != 'a')
	count++;
      else
	i++;
      i++;
    }
  if (count == 0 || count > 4)
    my_put_error("Wrong number of champs\n", 1, NULL, 0);
  return (count);
}

void	init_var_pars(t_parsing_arg *pars, char **av)
{
  pars->i = 0;
  pars->champ.prog_number = 0;
  pars->nb_champ = count_nb_champ(av);
  if ((pars->champ.reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    my_put_error("Malloc fail\n", 1, NULL, 0);
  pars->champ.mem_size[0] = -1;
  pars->champ.mem_size[1] = -1;
  pars->start = 0;
}

void	reset_var_pars(t_parsing_arg *pars)
{
  pars->champ.mem_size[0] = -1;
  pars->champ.mem_size[1] = -1;
  pars->champ.prog_number++;
  pars->i++;
}
