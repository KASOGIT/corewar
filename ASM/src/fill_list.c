/*
** get_param.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:45 2015 Manuel Trambert
** Last update Sun Apr 12 20:29:25 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "op.h"

char	*get_label_name(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i] != ':')
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[i] = '\0';
  return (tmp);
}

char	*get_line_label(char *str)
{
  int	i;
  int	e;
  char	*tmp;

  i = 0;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i] != ':')
    i += 1;
  while (str[++i] == ' ');
  while (str[i] != '\0')
    {
      tmp[e] = str[i];
      i += 1;
      e += 1;
    }
  tmp[e] = '\0';
  return (tmp);
}

void	my_new_line(t_champ **champ, char **text, int *i, int *e)
{
  if (islabel(text[*i]) == 1)
    (*champ)->label[(*e)++] = get_line_label(text[*i]);
  else
    (*champ)->label[(*e)++] = my_strdup(text[*i]);
  (*i) += 1;
  (*champ)->label[(*e)] = NULL;
}

void	get_label(t_champ **champ, char **text)
{
  int	i;
  int	e;

  init_get_label(&e, &i, champ, text);
  if (islabel(text[i]) == 1)
    {
      (*champ)->name = get_label_name(text[i++]);
      (*champ)->label[e] = get_line_label(text[e]);
      e += 1;
      (*champ)->label[e] = NULL;
    }
  while (text[i] != NULL)
    {
      if (islabel(text[i]) == 1 && i > 0)
	{
	  e = 0;
	  add_list(champ);
	  if (((*champ)->label
	       = malloc(sizeof(char*)
			* (size_new_label(text, i + 1) + 2))) == NULL)
	    exit(EXIT_FAILURE);
	  (*champ)->name = get_label_name(text[i]);
	}
      my_new_line(champ, text, &i, &e);
    }
}
