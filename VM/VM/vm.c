/*
** vm.c for vm in /home/soto_a/rendu/Corewar/VM
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar 23 12:58:37 2015 KASO soto
** Last update Sat Apr 11 00:05:46 2015 KASO soto
*/

#include "vm.h"

void	my_usage()
{
  my_putstr("Usage : ./corewar [-dump nbr_cycle]");
  my_putstr("[[-n prog_number] [-a load_address ] prog_name] ...");
  exit(EXIT_FAILURE);
}

int	verif_and_get_cycle_bef_end(char *data)
{
  int	i;

  i = 0;
  while (data[i])
    {
      if (!(data[i] >= '0' && data[i] <= '9'))
	my_usage();
      i++;
    }
  return (my_getnbr(data));
}

int		main(int ac, char **av)
{
  t_corewar	corewar;

  if (ac >= 4)
    {
      corewar.nb_cycle_bef_end = verif_and_get_cycle_bef_end(av[2]);
      my_init_list(&(corewar.champs));
      my_create_list(&corewar, av + 3);
      run_game(&corewar);
    }
  else
    my_usage();
  return (0);
}
