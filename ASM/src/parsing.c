/*
** parsing.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:53 2015 Manuel Trambert
** Last update Sun Apr 12 20:23:29 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "op.h"

void	init_get_file(int *i, int *bool)
{
  *i = 0;
  *bool = 0;
}

void	get_file(int fd, t_tmp *tmp_ptr)
{
  int	bool;
  char	*tmp;
  char	*str;
  int	i;

  if ((tmp_ptr->text = malloc(sizeof(char*) * (tmp_ptr->size + 3))) == NULL)
    exit(EXIT_FAILURE);
  init_get_file(&i, &bool);
  while ((str = get_next_line(fd)) != NULL)
    {
      if (check_null(str) != 1 && (tmp = epur_str(str)))
	{
	  if (tmp[0] != '.' && tmp[0] != '#')
	    {
	      tmp_ptr->text[i] = my_strdup(tmp);
	      i += 1;
	    }
	  else if (my_strncmp(tmp, ".name", 5) == 0)
	    get_name(tmp, tmp_ptr);
	  else if ((my_strncmp(tmp, ".comment", 7) == 0) || bool == 0)
	    bool = get_comment(tmp, tmp_ptr);
	}
      free(str);
    }
  tmp_ptr->text[i] = NULL;
}

int	loop_syntax(t_tmp *tmp_ptr)
{
  char	*tmp;
  char	**tab;
  int	bool;
  int	i;

  bool = 0;
  i = -1;
  while (tmp_ptr->text[++i] != NULL)
    {
      if (tmp_ptr->text[i][0] != '.' && tmp_ptr->text[i][0] != '#')
	{
	  tmp = kill_space(tmp_ptr->text[i]);
	  tab = my_str_to_wordtab(tmp);
	  if ((check_syntax(tab, i + 4, tmp_ptr->text)) == -1)
	    bool = -1;
	  free(tmp);
	  free_tab(tab);
	}
    }
  return (bool);
}

void	parsing(int fd, t_champ *champ, t_tmp *tmp)
{
  char	*str;
  int	bool;
  int	empty;

  empty = 0;
  tmp->size = 5;
  if ((bool = check_header(fd)) == -1)
    my_putstderr("Check your header\n");
  while ((str = get_next_line(fd)) != NULL)
    {
      if (check_null(str) == 0)
	empty = 1;
      if (check_label(str) == -1)
	my_putstderr("Compile error: After a label, write a command\n");
      tmp->size += 1;
      free(str);
    }
  if (empty == 0)
    my_putstderr("Compile error: You should write command\n");
  lseek(fd, 0, SEEK_SET);
  get_file(fd, tmp);
  get_label(&champ, tmp->text);
  bool = loop_syntax(tmp);
  if (bool == -1)
    exit(EXIT_FAILURE);
}
