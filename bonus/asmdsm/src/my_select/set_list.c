/*
** set_list.c for  in /home/trambe_m/My_select/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Tue Jan  6 02:13:36 2015 Manuel Trambert
** Last update Sun Apr 12 21:28:22 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my_select.h"

int		finish_list(t_list **ptr, t_list **end)
{
  (*ptr)->line = 0;
  (*ptr)->prev = *end;
  (*end)->next = *ptr;
  return (0);
}

void		set_pass(t_list *ptr, t_pos *pos)
{
  if ((pos->pos_x = pos->pos_x + (pos->cpt + 1)) >= pos->sizex)
    {
      pos->pos_y += 2;
      pos->pos_x = 0;
    }
  if (pos->pos_y < pos->sizey)
    ptr->pass = 1;
  else if (pos->pos_y > pos->sizey)
    ptr->pass = 0;
}

int		set_buff(char *str, t_list **ptr, t_list **end, t_pos *pos)
{
  DIR		*buffer;
  struct dirent	*name;
  t_list	*tmp;

  if ((buffer = opendir(str)) == NULL)
    return (1);
  pos->nb = 0;
  pos->open = 1;
  while ((name = readdir(buffer)) != NULL)
    {
      tmp = xmalloc(sizeof(t_list));
      tmp->name = my_strdup(name->d_name);
      (*ptr)->line = 0;
      pos->nb += 1;
      tmp->next = NULL;
      tmp->prev = NULL;
      tmp->next = *ptr;
      if (*end == NULL)
	*end = tmp;
      *ptr = tmp;
    }
  finish_list(ptr, end);
  closedir(buffer);
  return (0);
}

char	*set_path(char *path, char *str)
{
  int	size;
  int	begin;
  char	*tmp;
  int	i;
  int	e;

  i = 0;
  e = -1;
  begin = my_strlen(str);
  size = my_strlen(path);
  tmp = xmalloc(sizeof(char) * (size  + begin + 10));
  if (begin > 0)
    while (str[i] != '\0')
      {
	tmp[i] = str[i];
	i++;
      }
  while (path[++e] != '\0')
    tmp[i++] = path[e];
  if (path[size - 1] != '/')
    tmp[i++] = '/';
  tmp[i] = '\0';
  return (tmp);
}

int		set_list(char **str, t_list **ptr, t_list **end, t_pos *pos)
{
  int	i;
  t_list	*tmp;

  i = 0;
  pos->path = xmalloc(sizeof(char));
  pos->path[0] = '\0';
  pos->path = set_path(str[1], pos->path);
  if (set_buff(pos->path, ptr, end, pos) == 1)
    {
      pos->open = 0;
      while (i++ < pos->nb)
	{
	  tmp = xmalloc(sizeof(t_list));
	  tmp->name = my_strdup(str[i]);
	  (*ptr)->line = 0;
	  tmp->next = NULL;
	  tmp->prev = NULL;
	  tmp->next = *ptr;
	  if (*end == NULL)
	    *end = tmp;
	  *ptr = tmp;
	}
      finish_list(ptr, end);
    }
  return (0);
}
