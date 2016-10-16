/*
** size.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr  4 20:47:37 2015 Manuel Trambert
** Last update Sat Apr  4 20:47:54 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my.h"

int	get_size(t_champ *champ)
{
  int	size;

  size = 1;
  while (champ != NULL)
    {
      champ->adress = size;
      size += size_parameter(champ);
      champ = champ->next;
    }
  return (size);
}

int		get_champ(t_champ *champ, t_tmp *tmp)
{
  tmp->print = champ;
  tmp->head->prog_size = get_size(tmp->print) - 1;
  return (0);
}
