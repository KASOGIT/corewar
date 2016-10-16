/*
** init.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr  4 20:49:51 2015 Manuel Trambert
** Last update Sun Apr 12 18:19:35 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my.h"

void	my_bzero(char *str, int end)
{
  int	i;

  i = 0;
  while (i <= end)
    {
      str[i] = '\0';
      i += 1;
    }
}

void	init_get_label(int *e, int *i, t_champ **champ, char **text)
{
  *i = 0;
  *e = 0;
  if (((*champ)->label = malloc(sizeof(char*)
				* (size_new_label(text, *i + 1) + 2))) == NULL)
    exit(EXIT_FAILURE);
  (*champ)->name = NULL;

}

void	init_champ(t_champ *champ, t_tmp *tmp)
{
  tmp->head->magic = COREWAR_EXEC_MAGIC;
  champ->name = NULL;
  champ->label = NULL;
  champ->next = NULL;
  champ->adress = 1;
}
