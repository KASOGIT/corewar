/*
** my_select.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Mon Dec 22 08:20:49 2014 Manuel Trambert
** Last update Sun Apr 12 21:34:23 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my_select.h"

void	pos_curs(t_list *ptr, t_list *end, t_pos *pos)
{
  if (pos->curs < pos->nb)
    {
      pos->curs += 1;
      while (ptr->next->line == 1 && ptr->next != end)
	{
	  pos->curs += 1;
	  ptr = ptr->next;
	}
      if (pos->curs >= pos->nb)
	pos->curs = 0;
    }
  else
    pos->curs = 0;
}

void	select_arg(t_list *ptr, t_list *end, t_pos *pos)
{
  int	i;

  i = 0;
  ptr = end;
  ptr = ptr->next;
  while (i++ < pos->curs)
    ptr = ptr->next;
  if (ptr->line == 1)
    {
      pos->space -= 1;
      ptr->line = 0;
      return ;
    }
  else
    {
      ptr->line = 1;
      pos->space += 1;
    }
  pos_curs(ptr, end, pos);
}

int	test_open(t_pos *pos, t_list *ptr, t_list *end)
{
  DIR		*buffer;
  char		*str;

  str = xmalloc(sizeof(char) * (my_strlen(ptr->name) + 1));
  if (pos->space != 1)
    return (1);
  ptr = get_ptr(ptr, end);
  pos->path = set_path(ptr->name, pos->path);
  if ((buffer = xopendir(pos->path)) == NULL)
    return (1);
  else
    {
      str = my_strdup(pos->path);
      pos->bool = 0;
      pos->resize = 1;
      pos->space = 0;
      pos->curs = 0;
      free(end);
      set_buff(str, &ptr, &end, pos);
      closedir(buffer);
      disp_list(ptr, end, pos);
    }
  return (0);
}

int	end_my_select(t_list *ptr, t_pos *pos, t_list *end)
{
  int	bool;

  bool = 0;
  if (pos->space > 1)
    return (0);
  if (test_open(pos, ptr, end) == 1)
    {
      if (pos->space == 1)
	{
	  ptr = get_ptr(ptr, end);
	  pos->path = unset_path(pos->path);
	}
      reset_term(pos);
      ptr = end;
      ptr = ptr->next;
      while (ptr != end && bool != 1)
	{
	  bool = disp_end(ptr, pos);
	  ptr = ptr->next;
	}
      if (bool == 0 && disp_end(ptr, pos) == 0)
	exit(-1);
      after_sdl(0, ptr->name, g_glob.flag);
    }
  return (0);
}
