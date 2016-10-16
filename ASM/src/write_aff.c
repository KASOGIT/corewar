/*
** write_aff.c for corewar in /home/julien_k/CPE_2014_corewar/ASM
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Tue Apr  7 22:39:53 2015 Kévin Julien
** Last update Sat Apr 11 04:19:40 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

void	write_aff(int dest, char **tmp, int *octet,
		  __attribute__((unused))t_champ *champ)
{
  char	aff;
  char	reg;
  char	cod;

  aff = 16;
  reg = my_get_nbr_core(tmp[1] + 1);
  cod = 64;
  write(dest, &aff, sizeof(char));
  write(dest, &cod, sizeof(char));
  write(dest, &reg, sizeof(char));
  (*octet) += 3;
}
