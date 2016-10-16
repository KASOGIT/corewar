/*
** list.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:48 2015 Manuel Trambert
** Last update Sat Apr 11 04:28:06 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my.h"

void		add_list(t_champ **ptr)
{
  t_champ	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit(EXIT_FAILURE);
  tmp->next = NULL;
  tmp->adress = 0;
  (*ptr)->next = tmp;
  *ptr = tmp;
}
