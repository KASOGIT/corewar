/*
** error.c for  in /home/trambe_m/PSU_2014_my_select/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Jan 10 12:05:23 2015 Manuel Trambert
** Last update Sun Apr 12 16:11:47 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "my_select.h"

char	*unset_path(char *str)
{
  int	i;

  i = my_strlen(str);
  while (str[i] != '/')
    i--;
  i--;
  while (str[i] != '/')
    i--;
  i++;
  str[i] = '\0';
  return (str);
}

int	reset_term(t_pos *pos)
{
  if ((pos->str = tgetstr("me", NULL)) == NULL)
    return (1);
  my_putttystr(pos->str);
  if ((pos->str = tgetstr("ve", NULL)) == NULL)
    return (1);
  my_putttystr(pos->str);
  if ((pos->str = tgetstr("cl", NULL)) == NULL)
    return (1);
  my_putttystr(pos->str);
  tcsetattr(0, TCSANOW, &g_glob.tmp);
  return (0);
}

void	finish_select()
{
  reset_term(g_glob.pos);
  tcsetattr(0, TCSANOW, &g_glob.tmp);
  if ((g_glob.pos->str = tgetstr("cl", NULL)) == NULL)
    return ;
  my_putttystr(g_glob.pos->str);
  tcsetattr(0, TCSANOW, &g_glob.tmp);
   exit(0);
}

int	my_size(t_pos *pos, t_list *end, t_list *ptr)
{
  if (((pos->nb / pos->sizeline) >= pos->sizey) && (pos->bool == 0))
    {
      if ((pos->str = tgetstr("cl", NULL)) == NULL)
	return (1);
      my_putttystr(pos->str);
      if ((pos->str = tgetstr("cm", NULL)) == NULL)
      	return (1);
      tputs(tgoto(pos->str, 90, 5), 1, my_putc);
      my_putttystr("too small window\n");
      pos->bool = 1;
      my_size(pos, end, ptr);
      while ((pos->nb / pos->sizeline) >= pos->sizey)
	{
	  signal(SIGWINCH, &resize);
	  signal(SIGINT, &finish_select);
	}
    }
  return (0);
}
