/*
** error.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 03:50:10 2015 Manuel Trambert
** Last update Sat Apr 11 03:53:43 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

int	check_syntax(char **tab, int line, char **text)
{
  int	e;
  int	i;

  e = (islabel(tab[0]) == 1) ? 1 : 0;
  i = 0;
  while (op_tab[i].mnemonique != NULL
	 && my_strcmp(tab[e], op_tab[i].mnemonique) != 1)
    i += 1;
  if (op_tab[i].mnemonique == NULL)
    {
      my_putstr("Compile error: Invalid command line: ", 2);
      my_put_nbr(line, 2);
      return (-1);
    }
  if (op_tab[i].nbr_args == 1)
    {
      if ((check_arg(tab[e + 1], line + 1, text, op_tab[i].type[0])) == -1)
	return (-1);
    }
  else
    if ((check_mul_arg(tab, line + 1, text, i)) == -1)
      return (-1);
  return (0);
}

int	check_empty_and_comment(int fd, char *str)
{
  int	bool;
  char	*tmp;

  bool = 0;
  if (str != NULL)
    {
      tmp = epur_str(str);
      if (tmp != NULL && my_strncmp(tmp, ".name", 5) != 0)
	{
	  my_putstr("Invalid file: You should write a .name\n", 2);
	  bool = -1;
	}
      free(str);
    }
  if ((str = get_next_line(fd)) == NULL)
    my_putstderr("Invalid file: miss .comment\n");
  tmp = epur_str(str);
  if (tmp != NULL && my_strncmp(tmp, ".comment", 8) != 0)
    {
      my_putstr("Invalid file: You should write a .comment\n", 2);
      bool = -1;
    }
  free(str);
  return (bool);
}

int	check_header(int fd)
{
  char	*str;
  int	bool;

  bool = 0;
  if ((str = get_next_line(fd)) == NULL)
    {
      my_putstderr("Invalid file: Empty\n");
      bool = -1;
    }
  if (str[0] == '#')
    {
      free(str);
      while ((str = get_next_line(fd)) != NULL && str[0] != '.')
	free(str);
    }
  bool = check_empty_and_comment(fd, str);
  if (bool == -1)
    return (-1);
  return (0);
}
