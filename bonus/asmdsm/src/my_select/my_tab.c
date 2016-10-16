/*
** my_tab.c for  in /home/trambe_m/PSU_2014_my_select/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Jan  9 03:14:57 2015 Manuel Trambert
** Last update Sun Apr 12 16:19:04 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my_select.h"

int	get_size_tab(char **board)
{
  int	i;

  i = 0;
  while (board[i] != NULL)
    i++;
  return (i);
}

char	**fill_tab(char **board)
{
  char	**table;
  int	i;
  int	size;

  i = 0;
  size = get_size_tab(board);
  table = xmalloc(sizeof(char*) * size);
  while (board[i] != NULL)
    {
      table[i] = board[i];
      i++;
    }
  return (table);
}
