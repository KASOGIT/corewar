/*
** line.c for  in /home/trambe_m/PSU_2014_my_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Jan 11 14:44:35 2015 Manuel Trambert
** Last update Sun Apr 12 16:11:21 2015 Manuel Trambert
*/

#include "my_select.h"

void	draw_all(t_pos *pos, int x, int y, char *str)
{
  tputs(tgoto(pos->str, x, y), 1, my_putc);
  my_putttystr(str);
  my_putttystr("-");
}

void	draw_line(t_pos *pos)
{
  int	x;
  int	y;

  x = 0;
  y = 9;
  while (x++ < pos->sizex - 2)
    draw_all(pos, x, y, "\033[36m");
  x = 0;
  y = pos->sizey;
  while (x++ < pos->sizex - 2)
    draw_all(pos, x, y, "\033[33m");
  x = 0;
  y = 0;
  while (x++ < pos->sizex - 2)
    draw_all(pos, x, y, "\033[33m");
  my_putttystr("\033[0m");
}

void	draw_side(t_pos *pos)
{
  int	x;
  int	y;

  x = 0;
  y = 1;
  while (y < pos->sizey - 1 && x < pos->sizex)
    {
      tputs(tgoto(pos->str, x, y), 1, my_putc);
      if (y + 2 == pos->sizey && x != pos->sizex - 1)
	{
	  x = pos->sizex - 1;
	  y = 0;
	}
      my_putttystr("\033[33m|");
      y++;
    }
  my_putttystr("\033[0m");
}

void	draw_pipe(t_pos *pos, int x, int y)
{
  tputs(tgoto(pos->str, x, y), 1, my_putc);
  my_putttychar('|');
}

void	draw_back(t_pos *pos, int x, int y)
{
  tputs(tgoto(pos->str, x - 2, y + 4), 1, my_putc);
  my_putttystr("\033[37m");
  my_putttychar('\\');
}
