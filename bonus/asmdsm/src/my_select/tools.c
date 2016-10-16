/*
** tools.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Tue Jan  6 02:23:32 2015 Manuel Trambert
** Last update Sun Apr 12 16:13:40 2015 Manuel Trambert
*/

#include <unistd.h>
#include <stdlib.h>

void	*xmalloc(int n)
{
  void	*value;

  if ((value = malloc(n)) == NULL)
    exit(0);
  return (value);
}
