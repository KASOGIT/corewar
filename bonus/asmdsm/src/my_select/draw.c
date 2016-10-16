/*
** draw.c for  in /home/trambe_m/PSU_2014_my_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Jan 10 12:29:44 2015 Manuel Trambert
** Last update Sun Apr 12 16:16:27 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my_select.h"

int	my_putty_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putttychar('-');
    }
  if (nb > 9)
    my_putty_nbr(nb / 10);
  my_putttychar(nb % 10 + 48);
  return (0);
}

void	draw_number(t_pos *pos)
{
  int	x;
  int	y;

  x = (pos->sizex / 2) - 40;
  y = 5;
  tputs(tgoto(pos->str, x, y), 1, my_putc);
  my_putttystr("nombre d'arguments total : ");
  my_putty_nbr(pos->nb);
  tputs(tgoto(pos->str, x, y + 1), 1, my_putc);
  my_putttystr("nombre d'arguments selectionné : ");
  my_putty_nbr(pos->space);
  tputs(tgoto(pos->str, x, y + 2), 1, my_putc);
  my_putttystr("nombre d'arguments supprimé : ");
  my_putty_nbr(pos->del);
}

void	draw_around(t_pos *pos)
{
  int	x;
  int	y;

  x = (pos->sizex / 2) - 2;
  y = 3;
  draw_back(pos, x, y);
  tputs(tgoto(pos->str, x, y - 1), 1, my_putc);
  while (x++ < ((pos->sizex / 2) + 10))
    my_putttystr("\033[37m-");
  draw_back(pos, x + 2, y - 4);
  while (y++ < 6)
    draw_pipe(pos, x, y);
  x = (pos->sizex / 2) - 2;
  tputs(tgoto(pos->str, x, y + 1), 1, my_putc);
  while (x++ < ((pos->sizex / 2) + 10))
    my_putttychar('-');
  tputs(tgoto(pos->str, x, y), 1, my_putc);
  my_putttychar('/');
  x = (pos->sizex / 2) - 4;
  while (y-- > 4)
    draw_pipe(pos, x, y);
  tputs(tgoto(pos->str, x, y), 1, my_putc);
  my_putttychar('/');
}
