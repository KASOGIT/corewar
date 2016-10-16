/*
** parsing_champ_load_champ.c for  in /home/soto_a/rendu/Corewar/linked_list
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Mar 28 22:10:55 2015 KASO soto
** Last update Sun Apr 12 15:13:32 2015 KASO soto
*/

#include "vm.h"

void	check_arg_and_set_value(char **av, t_parsing_arg *pars)
{
  int	*tmp_mem;

  if (av[0][0] == '-' && av[0][1] == 'a')
    {
      if (!av[1])
	my_put_error("Bad formed option -a\n", 1, NULL, 0);
      pars->start = check_and_set_start_mem(av[1]);
      tmp_mem = init_mem_per_champ(pars->nb_champ, &(pars->start));
      pars->champ.mem_size[0] = tmp_mem[0];
      pars->champ.mem_size[1] = tmp_mem[1];
      free(tmp_mem);
      pars->count_param++;
    }
  else if (av[0][0] == '-' && av[0][1] == 'n')
    {
      if (!av[1])
	my_put_error("Bad formed option -n\n", 1, NULL, 0);
      pars->champ.prog_number =
	check_and_get_prog_number(av[1], pars->champ.prog_number);
      pars->count_param++;
    }
}

void	read_and_check_info_champ(t_champ *champ, char *path_champ)
{
  int	fd_champ;

  if ((fd_champ = open(path_champ, O_RDONLY)) == -1)
    my_put_error("Problem champ open\n", 1, NULL, 0);
  if (read(fd_champ, &(champ->header), sizeof(header_t)) < 0)
    my_put_error("Can't read header\n", 1, NULL, 0);
  if (litle_endian())
    {
      champ->header.magic = litle_to_big(champ->header.magic);
      champ->header.prog_size = litle_to_big(champ->header.prog_size);
    }
  if (champ->header.magic != COREWAR_EXEC_MAGIC)
    my_put_error("Magic number doesn't match\n", 1, NULL, 0);
  get_size_and_init_prog(champ, fd_champ);
  close(fd_champ);
}

void	control_mem_placement(t_list **champs)
{
  t_list *tmp;
  t_list *tmp_forward;

  tmp = (*champs)->next;
  tmp_forward = tmp->next;
  while (tmp != *champs)
    {
      while (tmp_forward != *champs)
	{
	  if ((tmp->champ.mem_size[0] >= tmp_forward->champ.mem_size[0]
	       && tmp->champ.mem_size[0] <= tmp_forward->champ.mem_size[1])
	      || (tmp->champ.mem_size[1] >= tmp_forward->champ.mem_size[0]
		  && tmp->champ.mem_size[1] <= tmp_forward->champ.mem_size[1]))
	    my_put_error("Bad placement champs\n", 1, NULL, 0);
	  tmp_forward = tmp_forward->next;
	}
      tmp = tmp->next;
      tmp_forward = tmp->next;
    }
}

void		control_total_size_champs(t_list **champs)
{
  t_list	*tmp;
  int		size_total;

  tmp = (*champs)->next;
  size_total = 0;
  while (tmp != *champs)
    {
      size_total += tmp->champ.header.prog_size;
      tmp = tmp->next;
    }
  if (size_total >= MEM_SIZE)
    my_put_error("Total size of champs is larger than memory_size\n",
		 1, NULL, 0);
}

void	control_champ_load(t_list **champs, int nb_champ)
{
  if (nb_champ > 1)
    control_mem_placement(champs);
  control_total_size_champs(champs);
}
