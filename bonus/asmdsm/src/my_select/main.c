/*
** main.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Wed Jan  7 03:30:07 2015 Manuel Trambert
** Last update Sun Apr 12 16:47:35 2015 Manuel Trambert
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>
#include "my_select.h"

t_glob	g_glob;

void	resize()
{
  struct winsize	size;

  ioctl(g_glob.pos->tty, TIOCGWINSZ, &size);
  signal(SIGWINCH, resize);
  g_glob.pos->bool = 0;
  g_glob.pos->resize = 1;
  g_glob.pos->sizex = size.ws_col;
  g_glob.pos->sizey = size.ws_row;
  disp_list(g_glob.ptr, g_glob.end, g_glob.pos);
}

void		init_everything(int ac)
{
  g_glob.ptr = xmalloc(sizeof(t_list));
  g_glob.pos = xmalloc(sizeof(t_pos));
  g_glob.pos->curs = 0;
  g_glob.pos->resize = 1;
  g_glob.pos->nb = ac - 1;
  g_glob.pos->bool = 0;
  raw_mode(g_glob.pos);
  g_glob.end = NULL;
}

int		my_select(int ac, char **av)
{
  int		test;

  if ((tcgetattr(0, &g_glob.tmp)) < 0)
    return (1);
  init_everything(ac);
  g_glob.pos->av = av;
  g_glob.pos->table = fill_tab(av);
  signal(SIGWINCH, resize);
  signal(SIGINT, finish_select);
  if (ac > 1)
    {
      if ((test = set_list(g_glob.pos->table, &g_glob.ptr,
			   &g_glob.end, g_glob.pos)) == 0)
	if ((test = disp_list(g_glob.ptr, g_glob.end, g_glob.pos)) == 1)
	  {
	    tcsetattr(0, TCSANOW, &g_glob.tmp);
	    return (1);
	  }
    }
  if ((tcsetattr(0, TCSANOW, &g_glob.tmp)) < 0)
    return (1);
  return (0);
}
