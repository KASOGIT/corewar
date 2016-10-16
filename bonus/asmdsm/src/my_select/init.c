/*
** init.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Thu Jan  8 07:16:14 2015 Manuel Trambert
** Last update Sun Apr 12 21:45:01 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "my_select.h"

int	get_curs(t_pos *pos, t_list *ptr)
{
  if (ptr->line == 1)
    {
      if ((pos->str = tgetstr("mr", NULL)) == NULL)
	return (1);
      my_putttystr(pos->str);
    }
  if (pos->i == pos->curs)
    {
      if ((pos->str = tgetstr("us", NULL)) == NULL)
	return (1);
      my_putttystr(pos->str);
    }
  return (0);
}

void	init_sizeline(t_pos *pos)
{
  pos->del = 0;
  pos->sizeline = 0;
  pos->pos_x = 2;
  while (((pos->pos_x = pos->pos_x + (pos->cpt + 1)) < pos->sizex)
	 && (pos->pos_x + ((pos->cpt + 1) * 2)) <= pos->sizex)
    pos->sizeline += 1;
  pos->sizeline += 1;
  pos->sizecol = pos->nb - (pos->sizeline);
  pos->pos_x = 2;
}

void	init_curs(t_pos *pos)
{
  struct winsize	size;

  ioctl(pos->tty, TIOCGWINSZ, &size);
  pos->sizex = size.ws_col;
  pos->sizey = size.ws_row;
  pos->pos_x = 2;
  pos->pos_y = 10;
}

int	get_cpt(t_pos *pos, t_list *ptr)
{
  if (ptr == NULL)
    return (pos->cpt);
  if (pos == NULL)
    return (my_strlen(ptr->name));
  return (my_strlen(ptr->name) > pos->cpt)
    ? my_strlen(ptr->name) : pos->cpt;
}

int	init_pos(t_list *ptr, t_list *end, t_pos *pos)
{
  pos->i = 0;
  ptr = end->next;
  pos->cpt = 0;
  while (ptr != end)
    {
      pos->cpt = get_cpt(pos, ptr);
      ptr = ptr->next;
    }
  pos->cpt = get_cpt(pos, ptr);
  pos->tty = open("/dev/tty", O_RDWR);
  if (pos->bool == 0 && pos->resize == 1)
    {
      pos->draw = 0;
      pos->space = 0;
      init_curs(pos);
      init_sizeline(pos);
      pos->resize = 0;
    }
  ptr = end->next;
  while ((ptr = ptr->next) != end)
    set_pass(ptr, pos);
  set_pass(ptr, pos);
  pos->pos_x = 2;
  pos->pos_y = 10;
  return (0);
}
