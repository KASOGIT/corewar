/*
** my_fct.c for  in /home/trambe_m/PSU_2014_my_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Jan 11 06:43:41 2015 Manuel Trambert
** Last update Sun Apr 12 17:31:11 2015 Manuel Trambert
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_select.h"

int	search_str(char *str, t_list *ptr, t_list *end)
{
  char	*buffer;
  int	test;

  buffer = xmalloc(sizeof(char) * 2);
  ptr = end;
  ptr = ptr->next;
  test = my_strlen(str);
  my_putttychar(str[test - 1]);
  while (ptr != end)
    {
      if ((test = (my_strcmp(ptr->name, str)) == 0)
	  || (test == 2))
	{
	  my_putttystr(" is it what you want ?");
	  buffer = xmalloc(sizeof(char) * 2);
	  read(0, buffer, 1);
	  if (buffer[0] == ENTER)
	    return (0);
	  else if (buffer[0] == ECHAP && buffer[1] == 0 && buffer[2] == 0)
	    return (2);
	  free(buffer);
	}
      ptr = ptr->next;
    }
  return (1);
}

int	is_alpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < 'a' && str[i] > 'Z') || (str[i] < 'A' && str[i] > '9')
	  || (str[i] < '0') || (str[i] > 'z') || (str[i] == '.')
	  || (str[i] == '/')
	  || (str[i] == '_') || (str[i] == '-') || str[i] == '*')
	return (1);
      i++;
    }
  return (0);
}

char	*my_strcopy(char *buffer, char *str)
{
  char	*tmp;
  int	i;
  int	e;

  e = 0;
  i = -1;
  tmp = xmalloc(sizeof(char) * my_strlen(str) + 2);
  if (is_alpha(buffer) == 1)
    return (str);
  if (str != NULL)
    while (str[++i] != '\0')
      tmp[i] = str[i];
  while (buffer[e] != '\0')
    {
      tmp[i] = buffer[e];
      e++;
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

t_list	*get_ptr(t_list *ptr, t_list *end)
{
  ptr = end;
  while (ptr->line != 1)
    ptr = ptr->next;
  return (ptr);
}
