/*
** chain_list.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Thu Jan  8 07:14:28 2015 Manuel Trambert
** Last update Sun Apr 12 17:30:06 2015 Manuel Trambert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_select.h"

void	del_node(t_list **ptr, t_list **end, t_pos *pos)
{
  int	i;

  i = 0;
  pos->del += 1;
  pos->nb -= 1;
  *ptr = *end;
  while (i++ < pos->curs)
    *ptr = (*ptr)->next;
  if ((*ptr)->next == *end)
    {
      (*ptr)->next = (*ptr)->next->next;
      *end = *ptr;
      pos->curs = 0;
    }
  else
    {
      (*ptr)->next = (*ptr)->next->next;
      (*ptr)->next->prev = (*ptr)->prev;
    }
}

void	add_node(t_list **ptr, t_pos *pos)
{
  t_list	*tmp;
  char		*buffer;
  char		*str;
  int		i;

  i = -1;
  buffer = xmalloc(sizeof(char) * 2);
  str = xmalloc(sizeof(char) * 2);
  tmp = xmalloc(sizeof(t_list));
  pos->nb += 1;
  str[0] = '\0';
  while (buffer[0] != ENTER)
    {
      read(0, buffer, 2);
      str = my_strcopy(buffer, str);
    }
  while (++i < pos->curs)
    *ptr = (*ptr)->next;
  tmp->name = my_strdup(str);
  tmp->line = 0;
  tmp->next = (*ptr)->next;
  (*ptr)->next = tmp;
  (*ptr)->next->next->prev = tmp;
  free(str);
}
