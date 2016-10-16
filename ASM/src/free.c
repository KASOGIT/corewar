/*
** free.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:34 2015 Manuel Trambert
** Last update Fri Apr  3 11:58:35 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	free_list(t_champ *champ)
{
  while (champ != NULL)
    {
      free_tab(champ->label);
      free(champ->name);
      champ = champ->next;
    }
}

void	free_end(t_tmp *tmp, int fd, int dest, t_champ *champ)
{
  free_list(champ);
  free_tab(tmp->text);
  free(tmp->head);
  free(tmp->print);
  free(tmp);
  close(fd);
  close(dest);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
}
