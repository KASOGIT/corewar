/*
** event.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Thu Jan  8 07:15:04 2015 Manuel Trambert
** Last update Sun Apr 12 16:11:26 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my_select.h"

int	get_event(char buffer[2], t_pos *pos, t_list **end, t_list **ptr)
{
  pos->draw = 0;
  if (buffer[0] == SPACE && buffer[1] == 0 && buffer[2] == 0)
    select_arg(*ptr, *end, pos);
  else if (buffer[0] == ENTER && buffer[1] == 0 && buffer[2] == 0)
    {
      end_my_select(*ptr, pos, *end);
      return (2);
    }
  else if ((buffer[0] == BACKSPACE && buffer[1] == 0 && buffer[2] == 0)
	   || (buffer[0] == DEL && buffer[1] == 91 && buffer[2] == 51))
    if (pos->nb > 1)
      del_node(ptr, end, pos);
    else
      {
	reset_term(pos);
	exit(0);
      }
  else if (buffer[0] == 27 && buffer[1] == 79 && buffer[2] == 81)
    {
      pos->draw = 1;
      my_search(pos, *ptr, *end);
    }
  else if (buffer[0] == 4 && buffer[1] == 0 && buffer[2] == 0)
    add_node(ptr, pos);
  return (0);
}

int	get_move(char buffer[2], t_pos *pos, t_list *end, t_list *ptr)
{
  int	test;

  if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == RIGHT)
    move_right(pos);
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == LEFT)
    move_left(pos);
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == UP)
    move_up(pos);
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == DOWN)
    move_down(pos);
  else if (buffer[0] == ECHAP && buffer[1] == 0 && buffer[2] == 0)
    {
      reset_term(pos);
      exit(0);
    }
  else
    {
      if ((test = get_event(buffer, pos, &end, &ptr)) == 1)
	return (1);
      else if (test == 2)
	return (0);
    }
  disp_list(ptr, end, pos);
  return (0);
}
