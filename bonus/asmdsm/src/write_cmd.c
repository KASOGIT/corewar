/*
** write_cmd.c for corewar in /home/julien_k/CPE_2014_corewar/ASM/src
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Sat Apr  4 13:47:35 2015 Kévin Julien
** Last update Sat Apr 11 04:20:08 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my.h"
#include "op.h"

int	my_get_nbr_core(char *str)
{
  int	i;
  int	nb;
  int	neg;

  i = 0;
  nb = 0;
  neg = 0;
  if (str[i] == '-')
    {
      neg = 1;
      i++;
    }
  while ((str[i] >= '0' && str[i] <= '9') || str[i] != 0)
    {
      nb = nb * 10 + (str[i] - 48);
      i++;
    }
  if (neg == 1)
    return (-nb);
  return (nb);
}

void	write_live(int dest, char **tmp, int *octet,
		   __attribute__((unused))t_champ *champ)
{
  char	live;
  int	value;

  live = 1;
  value = my_get_nbr_core(tmp[1] + 1);
  if (litle_endian() == 1)
    value = litle_to_big(value);
  write(dest, &live, 1);
  write(dest, &value, 4);
  (*octet) += 5;
}

short	litle_to_big_short(short val)
{
  return ((val << 8) | ((val >> 8) & 0xFF));
}

void	write_fork(int dest, char **tmp, int *octet, t_champ *champ)
{
  int	where;
  char	fork;
  short	pos;

  fork = 12;
  if (param_islabel(tmp[1]) == 1)
    {
      tmp[1] += 2;
      while (my_strcmp(tmp[1], champ->name) != 1)
	champ = champ->next;
      where = champ->adress - (*octet);
    }
  else
    where = my_get_nbr_core(tmp[1] + 1);
  pos = where;
  if (litle_endian() == 1)
    pos = litle_to_big_short(pos);
  write(dest, &fork, 1);
  write(dest, &pos, 2);
  (*octet) += 3;
}

void	write_zjmp(int dest, char **tmp, int *octet, t_champ *champ)
{
  char  fork;
  short pos;

  fork = 9;
  if (param_islabel(tmp[1]) == 1)
    {
      tmp[1] += 2;
      while (my_strcmp(tmp[1], champ->name) != 1)
	champ = champ->next;
      pos = champ->adress - (*octet);
    }
  else
    pos = my_get_nbr_core(tmp[1] + 1);
  if (litle_endian() == 1)
    pos = litle_to_big_short(pos);
  write(dest, &fork, sizeof(char));
  write(dest, &pos, sizeof(short));
  (*octet) += 3;
}
