/*
** move.c for  in /home/trambe_m/PSU_2014_my_select/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Jan 10 10:35:52 2015 Manuel Trambert
** Last update Sun Apr 12 16:11:17 2015 Manuel Trambert
*/

#include "my_select.h"

void	move_curs(t_pos *pos, t_list *ptr, char *str, t_list *end)
{
  int	i;
  int	curs;

  curs = 0;
  i = 0;
  ptr = end;
  ptr = ptr->next;
  while (my_strcmp(ptr->name, str) != 0)
    {
      ptr = ptr->next;
      i++;
    }
  while (curs < i)
    curs++;
  pos->curs = curs;
}

void	move_right(t_pos *pos)
{
  if (pos->curs < pos->nb - 1)
    pos->curs += 1;
  else
    pos->curs = 0;
}

void	move_left(t_pos *pos)
{
  if (pos->curs > 0)
    pos->curs -= 1;
  else
    pos->curs = pos->nb - 1;
}

void	move_up(t_pos *pos)
{
  if (pos->curs > pos->sizeline - 1)
    pos->curs -= pos->sizeline;
  else
    if ((pos->curs += pos->sizeline * (pos->nb / pos->sizeline)) > pos->nb - 1)
      pos->curs = pos->nb - 1;
}

void	move_down(t_pos *pos)
{
  if (pos->curs < pos->sizecol)
    pos->curs += pos->sizeline;
  else
    if ((pos->curs -= pos->sizeline * (pos->nb / pos->sizeline)) < 0)
      pos->curs += pos->sizeline;
}
