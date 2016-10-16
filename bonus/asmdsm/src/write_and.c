/*
** write_and.c for corewar in /home/julien_k/CPE_2014_corewar/ASM
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Tue Apr  7 17:06:49 2015 Kévin Julien
** Last update Thu Apr  9 10:15:23 2015 Kévin Julien
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

void	check_codand(int dest, char **param, int *octet)
{
  char	cod;
  char	and;
  int	i;

  and = 6;
  cod = 0;
  i = 0;
  while (param[i] != NULL)
    {
      if (param[i][0] == 'r')
	cod++;
      else if (param[i][0] == '%')
	cod += 2;
      else
	cod += 3;
      cod <<= 2;
      i++;
    }
  write(dest, &and, sizeof(char));
  write(dest, &cod, sizeof(char));
  (*octet) += 2;
}

void	check_labeland(int dest, char *str, int *octet, t_champ *champ)
{
  int	ind;

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
    ind = litle_to_big(ind);
  write(dest, &ind, sizeof(int));
  (*octet) += 4;
}

void	check_paramand(int dest, char *str, int *octet, t_champ *champ)
{
  short	dir;
  char	reg;

  if (str[0] == 'r')
    {
      reg = my_get_nbr_core(str + 1);
      write(dest, &reg, sizeof(char));
      (*octet)++;
    }
  else if (str[0] == '%')
    check_labeland(dest, str, octet, champ);
  else
    {
      dir = my_get_nbr_core(str);
      if (litle_endian() == 1)
	dir = litle_to_big_short(dir);
      write(dest, &dir, sizeof(short));
      (*octet) += 2;
    }
}

void	write_and(int dest, char **tmp, int *octet, t_champ *champ)
{
  char	**param;
  int	i;

  param = cut_parameter(tmp[1]);
  i = 0;
  check_codand(dest, param, octet);
  while (param[i] != NULL)
    {
      check_paramand(dest, param[i], octet, champ);
      i++;
    }
}
