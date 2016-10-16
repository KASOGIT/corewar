/*
** parsing_champ_check_set.c for check_set_champ in /home/soto_a/rendu/Corewar/linked_list
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Mar 28 22:07:04 2015 KASO soto
** Last update Sun Apr 12 10:41:29 2015 KASO soto
*/

#include "vm.h"

void    init_champ(t_champ *champ)
{
  int   i;

  i = 0;
  champ->header.magic = 0;
  champ->header.prog_size = 0;
  while (i <= PROG_NAME_LENGTH)
    {
      champ->header.prog_name[i] = 0;
      i++;
    }
  i = 0;
  while (i <= COMMENT_LENGTH)
    {
      champ->header.comment[i] = 0;
      i++;
    }
  i = 0;
  while (i <= 4096)
    {
      champ->prog[i] = 0;
      i++;
    }
}

int     check_and_get_prog_number(char *new_prog_nb, int old_prog_nb)
{
  int   n_p_nb;
  int   i;

  i = 0;
  while (new_prog_nb[i])
    {
      if (!(new_prog_nb[i] >= '0' && new_prog_nb[i] <= '9'))
        my_put_error("bad formed prog number\n", 1, NULL, 0);
      i++;
    }
  n_p_nb = my_getnbr(new_prog_nb);
  if (n_p_nb == old_prog_nb - 1)
    my_put_error("Two champ  was set with the same number\n", 1, NULL, 0);
  return (n_p_nb);
}

int     *init_mem_per_champ(int nb_champ, int *start)
{
  int   size_mem;
  int   *pos_mem;

  size_mem = MEM_SIZE / nb_champ - 1;
  if (*start >= MEM_SIZE)
    my_put_error("-a option set over the MEM_SIZE\n", 1, NULL, 0);
  if ((pos_mem = malloc(sizeof(int) * 2)) == NULL)
    my_put_error("Malloc failed\n", 1, NULL, 0);
  pos_mem[0] = *start;
  pos_mem[1] = (*start + size_mem >= MEM_SIZE)
    ? (*start + size_mem) - MEM_SIZE : *start + size_mem;
  *start = (pos_mem[1] + 1) >= MEM_SIZE ? 0 : pos_mem[1] + 1;
  return (pos_mem);
}

void    get_size_and_init_prog(t_champ *champ, int fd_champ)
{
  if (read(fd_champ, champ->prog, champ->header.prog_size) < 0)
    my_put_error("Error on read champ in .cor\n", 1, NULL, 0);
  champ->prog[champ->header.prog_size] = '\0';
}

int     check_and_set_start_mem(char *nb)
{
  int   i;

  i = 0;
  while (nb[i])
    {
      if (!(nb[i] >= '0' && nb[i] <= '9'))
	my_put_error("Bad formed -a option\n", 1, NULL, 0);
      i++;
    }
  return (my_getnbr(nb));
}
