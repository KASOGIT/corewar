/*
** set.c for  in /home/trambe_m/PSU_2014_my_select/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Jan 10 09:37:14 2015 Manuel Trambert
** Last update Sun Apr 12 16:11:02 2015 Manuel Trambert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_select.h"

char	*set_str(char *str)
{
  str = NULL;
  free(str);
  str = xmalloc(sizeof(char) * 2);
  str[0] = '\0';
  return (str);
}

int	my_search(t_pos *pos, t_list *ptr, t_list *end)
{
  int	match;
  char	*buffer;
  char	*str;

  buffer = xmalloc(sizeof(char) * 2);
  str = xmalloc(sizeof(char) * 2);
  str[0] = '\0';
  while ((match = search_str(str, ptr, end)) == 1)
    {
      read(0, buffer, 2);
      str = my_strcopy(buffer, str);
      if (buffer[0] == BACKSPACE)
	str = set_str(str);
      if (buffer[0] == ECHAP && buffer[1] == 0 && buffer[2] == 0)
	return (0);
      tputs(tgoto(pos->str, 5, 5), 1, my_putc);
    }
  if (match == 0)
    move_curs(pos, ptr, str, end);
  str = NULL;
  free(str);
  free(buffer);
  return (0);
}

void	raw_mode(t_pos *pos)
{
  struct termios	*term;

  term = xmalloc(sizeof(struct termios));
  if ((tcgetattr(0, term)) < 0)
    return ;
  if ((tgetent(NULL, "xterm")) < 0)
   return ;
  term->c_lflag &= ~(ICANON | ECHO);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, term) == -1)
    {
      write(pos->tty, "fail\n", 5);
      return ;
    }
}

int	unset_curs(t_pos *pos)
{
  if ((pos->str = tgetstr("vi", NULL)) == NULL)
    return (1);
  my_putttystr(pos->str);
  return (0);
}
