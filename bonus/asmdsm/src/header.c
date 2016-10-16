/*
** header.c for  in /home/trambe_m/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr 11 03:50:12 2015 Manuel Trambert
** Last update Sat Apr 11 03:50:13 2015 Manuel Trambert
*/

#include "my.h"

void	get_name(char *str, t_tmp *ptr)
{
  int	i;
  int	e;

  i = -1;
  e = 0;
  while (e < PROG_NAME_LENGTH + 1)
    {
      ptr->head->prog_name[e] = '\0';
      e += 1;
    }
  e = 0;
  while (str[++i] != '"');
  while (str[++i] != '"')
    {
      ptr->head->prog_name[e] = str[i];
      e += 1;
    }
  ptr->head->prog_name[e] = '\0';
}

int		get_comment(char *str, t_tmp *ptr)
{
  int		i;
  static int	e = 0;

  i = -1;
  if (e == 0)
    {
      while (e < COMMENT_LENGTH + 1)
	{
	  ptr->head->comment[e] = '\0';
	  e += 1;
	}
      e = 0;
    }
  if (my_strncmp(str, ".comment", 7) == 0)
    while (str[++i] != '"');
  while (str[++i] != '"' && str[i] != '\0')
    {
      ptr->head->comment[e] = str[i];
      e += 1;
    }
  ptr->head->comment[e] = '\0';
  if (str[i] == '"')
    return (1);
  return (0);
}
