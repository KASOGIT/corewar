/*
** disp.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Thu Jan  8 07:17:59 2015 Manuel Trambert
** Last update Sun Apr 12 20:57:58 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my_select.h"

int	disp_end(t_list *ptr, __attribute__((unused))t_pos *pos)
{
  if (ptr->line == 1)
    return (1);
  return (0);
}

int	disp_str(t_list *ptr, t_pos *pos)
{
  if ((get_curs(pos, ptr)) == 1)
    return (1);
  if ((pos->str = tgetstr("cm", NULL)) == NULL)
    return (1);
  tputs(tgoto(pos->str, pos->pos_x, pos->pos_y), 1, my_putc);
  my_putttystr(ptr->name);
  if (((pos->pos_x = pos->pos_x + (pos->cpt + 1)) >= pos->sizex)
      || (pos->pos_x + ((pos->cpt + 1)) * 2) >= pos->sizex)
    {
      pos->pos_x = 2;
      pos->pos_y += 1;
    }
  if ((pos->str = tgetstr("me", NULL)) == NULL)
    return (1);
  my_putttystr(pos->str);
  if ((pos->str = tgetstr("ue", NULL)) == NULL)
    return (1);
  my_putttystr(pos->str);
  pos->i += 1;
  return (0);
}

void	disp_start(t_pos *pos)
{
  if ((pos->str = tgetstr("cl", NULL)) == NULL)
    return ;
  my_putttystr(pos->str);
  if ((pos->str = tgetstr("cm", NULL)) == NULL)
    return ;
  tputs(tgoto(pos->str, pos->sizex / 2, 5), 1, my_putc);
  my_putttystr("\033[1m\033[4m\033[36mMy_select");
  my_putttystr("\033[0m");
  draw_side(pos);
  draw_around(pos);
  draw_line(pos);
  draw_number(pos);
  my_putttystr("\033[0m");
}

int	disp_pos(t_list *ptr, t_list *end, t_pos *pos)
{
  char	buffer[2];
  int	test;

  ptr = end;
  buffer[0] = 0;
  buffer[1] = 0;
  buffer[2] = 0;
  while ((ptr = ptr->next) != end)
    if (pos->pos_y < pos->sizey && pos->pos_x < pos->sizex)
      disp_str(ptr, pos);
  if ((disp_str(ptr, pos)) != 0)
    return (1);
  unset_curs(pos);
  while (read(0, buffer, 3) != 0)
    if ((test = get_move(buffer, pos, end, ptr)) == 1)
      {
	write(1, "error\n", 6);
	return (1);
      }
    else if (test == 0)
      return (2);
  return (0);
}

int	disp_list(t_list *ptr, t_list *end, t_pos *pos)
{
  int	test;

  init_pos(ptr, end, pos);
  if ((my_size(pos, end, ptr)) == 2)
    return (2);
  if (pos->draw != 1)
    {
      disp_start(pos);
      pos->draw = 1;
    }
  if ((test = disp_pos(ptr, end, pos)) == 1)
    return (1);
  return (0);
}
