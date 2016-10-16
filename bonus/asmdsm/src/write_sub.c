/*
** write_sub.c for corewar in /home/julien_k/CPE_2014_corewar/ASM
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Tue Apr  7 14:56:05 2015 Kévin Julien
** Last update Sat Apr 11 04:21:15 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

void	write_add(int dest, char **tmp, int *octet,
		  __attribute__((unused))t_champ *champ)
{
  char	sub;
  char	r1;
  char	r2;
  char	r3;
  char	cod;
  char	**param;

  cod = 84;
  sub = 4;
  param = cut_parameter(tmp[1]);
  r1 = my_get_nbr_core(param[0] + 1);
  r2 = my_get_nbr_core(param[1] + 1);
  r3 = my_get_nbr_core(param[2] + 1);
  write(dest, &sub, sizeof(char));
  write(dest, &cod, sizeof(char));
  write(dest, &r1, sizeof(char));
  write(dest, &r2, sizeof(char));
  write(dest, &r3, sizeof(char));
  (*octet) += 5;
}

void	write_sub(int dest, char **tmp, int *octet,
		  __attribute__((unused))t_champ *champ)
{
  char	sub;
  char	r1;
  char	r2;
  char	r3;
  char	cod;
  char	**param;

  cod = 84;
  sub = 5;
  param = cut_parameter(tmp[1]);
  r1 = my_get_nbr_core(param[0] + 1);
  r2 = my_get_nbr_core(param[1] + 1);
  r3 = my_get_nbr_core(param[2] + 1);
  write(dest, &sub, sizeof(char));
  write(dest, &cod, sizeof(char));
  write(dest, &r1, sizeof(char));
  write(dest, &r2, sizeof(char));
  write(dest, &r3, sizeof(char));
  (*octet) += 5;
}
