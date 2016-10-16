/*
** my_tty.c for  in /home/trambe_m/PSU_2014_my_select/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Thu Jan  8 23:55:31 2015 Manuel Trambert
** Last update Sun Apr 12 16:12:24 2015 Manuel Trambert
*/

#include <unistd.h>
#include "my_select.h"

void	my_putttychar(char e)
{
  write(g_glob.pos->tty, &e, 1);
}

int	my_putc(int e)
{
  my_putttychar(e);
  return (0);
}

void	my_putttystr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putttychar(str[i]);
      i++;
    }
}
