/*
** write_and.c for corewar in /home/julien_k/CPE_2014_corewar/ASM
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Tue Apr  7 17:06:49 2015 Kévin Julien
** Last update Sat Apr 11 04:20:28 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

void	check_labellfork(int dest, char *str, int *octet, t_champ *champ)
{
  short	ind;

  if (str[1] == ':')
    {
      str += 2;
      while (my_strcmp(str, champ->name) != 1)
	champ = champ->next;
      ind = champ->adress - (*octet) + 1;
    }
  else
    ind = my_get_nbr_core(str + 1);
  if (litle_endian() == 1)
    ind = litle_to_big_short(ind);
  write(dest, &ind, sizeof(short));
}

void	write_lfork(int dest, char **tmp, int *octet, t_champ *champ)
{
  char	**param;
  char	lfork;

  lfork = 15;
  write(dest, &lfork, sizeof(char));
  param = cut_parameter(tmp[1]);
  check_labellfork(dest, param[0], octet, champ);
  (*octet) += 3;
}
