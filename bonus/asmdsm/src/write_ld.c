/*
** write_ld.c for corewar in /home/julien_k/CPE_2014_corewar/ASM
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Tue Apr  7 16:48:01 2015 Kévin Julien
** Last update Sat Apr 11 04:20:19 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

void	check_ld(int dest, int *octet, char **param)
{
  char	cod;
  short	value;

  cod = 3;
  cod = ((cod << 2) + 1) << 4;
  write(dest, &cod, sizeof(char));
  value = my_get_nbr_core(param[0]);
  if (litle_endian() == 1)
    value = litle_to_big_short(value);
  write(dest, &value, sizeof(short));
  (*octet) += 5;
}

void	check_ld_dir(int dest, int *octet, char **param)
{
  char	cod;
  int	value;

  cod = 2;
  cod = ((cod << 2) + 1) << 4;
  write(dest, &cod, sizeof(char));
  value = my_get_nbr_core(param[0] + 1);
  if (litle_endian() == 1)
    value = litle_to_big(value);
  write(dest, &value, sizeof(int));
  (*octet) += 7;
}

void    write_ld(int dest, char **tmp, int *octet,
		 __attribute__((unused))t_champ *champ)
{
  char  ld;
  int   tmpreg;
  char  **param;

  ld = 2;
  write(dest, &ld, sizeof(char));
  param = cut_parameter(tmp[1]);
  if (tmp[1][0] == '%')
    check_ld_dir(dest, octet, param);
  else
    check_ld(dest, octet, param);
  tmpreg = my_get_nbr_core(param[1] + 1);
  write(dest, &tmpreg, sizeof(char));
}
