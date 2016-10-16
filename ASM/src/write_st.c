/*
** write_st.c for corewar in /home/julien_k/CPE_2014_corewar/ASM
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Tue Apr  7 15:25:12 2015 Kévin Julien
** Last update Sat Apr 11 04:20:41 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

void	check_codst(int dest, char **param)
{
  char	cod;
  char	st;
  int	i;

  st = 3;
  cod = 0;
  i = 0;
  while (param[i] != NULL)
    {
      if (param[i][0] == 'r')
        cod += 1;
      else
        cod += 3;
      i++;
      cod <<= 2;
    }
  cod <<= 2;
  write(dest, &st, sizeof(char));
  write(dest, &cod, sizeof(char));
}

void	write_st(int dest, char **tmp, int *octet,
		 __attribute__((unused))t_champ *champ)
{
  char	**param;
  char	r1;
  char	r2;
  short	ind;

  param = cut_parameter(tmp[1]);
  check_codst(dest, param);
  (*octet) += 3;
  r1 = my_get_nbr_core(param[0] + 1);
  write(dest, &r1, sizeof(char));
  if (param[1][0] == 'r')
    {
      r2 = my_get_nbr_core(param[1] + 1);
      write(dest, &r2, sizeof(char));
      (*octet)++;
    }
  else
    {
      ind = my_get_nbr_core(param[1]);
      if (litle_endian() == 1)
	ind = litle_to_big_short(ind);
      write(dest, &ind, sizeof(short));
      (*octet) += 2;
    }
}
