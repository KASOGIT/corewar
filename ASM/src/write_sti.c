/*
** write_sti.c for corewar in /home/julien_k/CPE_2014_corewar/ASM
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Mon Apr  6 18:55:09 2015 Kévin Julien
** Last update Thu Apr  9 15:43:05 2015 Kévin Julien
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

void    sti_param(char *str, int bool, int *octet, int dest)
{
  char  reg;
  short param;

  if (bool == 1)
    {
      param = my_get_nbr_core(str + 1);
      if (litle_endian() == 1)
        param = litle_to_big_short(param);
      write(dest, &param, sizeof(short));
      (*octet) += 2;
    }
  else if (bool == 0)
    {
      reg = my_get_nbr_core(str + 1);
      write(dest, &reg, sizeof(char));
      (*octet) += 1;
    }
  else if (bool == 2)
    {
      param = my_get_nbr_core(str);
      if (litle_endian() == 1)
        param = litle_to_big_short(param);
      write(dest, &param, sizeof(short));
      (*octet) += 2;
    }
}

void	check_cod(int dest, char **param)
{
  int	i;
  char	cod;

  i = 1;
  cod = 1;
  while (param[i] != NULL)
    {
      if (param[i][0] == 'r')
        cod = (cod << 2) + 1;
      else if (param_islabel(param[i]) == 1)
        cod = (cod << 2) + 2;
      else if (param[i][0] == '%')
        cod = (cod << 2) + 2;
      else
        cod = (cod << 2) + 3;
      i++;
    }
  cod <<= 2;
  write(dest, &cod, sizeof(char));
}

void	check_param(int dest, char **param, int *octet, t_champ *champ)
{
  int	i;
  short	param2;

  i = 1;
  while (param[i] != NULL)
    {
      if (param[i][0] == 'r')
        sti_param(param[i], 0, octet, dest);
      else if (param_islabel(param[i]) == 1)
        {
          param[i] += 2;
          while (my_strcmp(param[i], champ->name) != 1)
            champ = champ->next;
          param2 = champ->adress - (*octet) + 3;
          if (litle_endian() == 1)
            param2 = litle_to_big_short(param2);
          write(dest, &param2, sizeof(short));
          (*octet) += 2;
        }
      else if (param[i][0] == '%')
        sti_param(param[i], 1, octet, dest);
      else
        sti_param(param[i], 2, octet, dest);
      i++;
    }
}

void    write_sti(int dest, char **tmp, int *octet, t_champ *champ)
{
  char  sti;
  char  reg;
  char  **param;

  sti = 11;
  param = cut_parameter(tmp[1]);
  write(dest, &sti, sizeof(char));
  check_cod(dest, param);
  reg = my_get_nbr_core(param[0] + 1);
  write(dest, &reg, sizeof(char));
  (*octet) += 3;
  check_param(dest, param, octet, champ);
}
