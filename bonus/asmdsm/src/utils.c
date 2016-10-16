/*
** utils.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:14 2015 Manuel Trambert
** Last update Fri Apr  3 11:58:15 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "op.h"

void	my_putchar(char e, int fd)
{
  write(fd, &e, 1);
}

void	my_putstderr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i += 1;
    }
  exit(-1);
}

void	my_put_nbr(int nb, int fd)
{
  int	div;

  if (nb == -2147483648)
    {
      my_putstr("-2147483648", fd);
      return ;
    }
  if (nb < 0)
    {
      nb = (-1) * nb;
      my_putchar('-', fd);
    }
  div = 1;
  while (nb / div > 9)
    div = div * 10;
  while (div != 0)
    {
      my_putchar('0' + (nb / div) % 10, fd);
      nb = nb % div;
      div = div / 10;
    }
  if (fd == 2)
    my_putchar('\n', fd);
}

char	*get_name_file(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 3))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i] != '.')
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[i] = str[i];
  tmp[i + 1] = 'c';
  tmp[i + 2] = 'o';
  tmp[i + 3] = 'r';
  tmp[i + 4] = '\0';
  return (tmp);
}
