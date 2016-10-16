/*
** asm.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr  4 20:44:15 2015 Manuel Trambert
** Last update Sat Apr 11 04:25:57 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "op.h"

int	check_name_file(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  if (i == 1)
    return (-1);
  if (str[i] != 's' || str[i - 1] != '.')
    return (-1);
  return (0);
}

void	open_file(char *str, int *fd)
{
  if (check_name_file(str) == -1)
    my_putstderr("Open: invalid name file. Should have a .s\n");
  if ((*fd = open(str, O_RDONLY)) == -1)
    my_putstderr("Open: source fail\n");
}

int	main(int ac, char **av)
{
  t_tmp		*tmp;
  int		fd;
  t_champ	*champ;
  int		dest;

  if (ac != 2)
    my_putstderr("Usage: ./asm prog_name (.s)\n");
  if ((champ = malloc(sizeof(*champ))) == NULL)
    return (-1);
  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  if ((tmp->head = malloc(sizeof(header_t))) == NULL)
    return (-1);
  tmp->print = champ;
  init_champ(champ, tmp);
  open_file(av[1], &fd);
  parsing(fd, champ, tmp);
  if ((dest = open(get_name_file(av[1]), O_RDWR | O_CREAT | O_TRUNC,
		   0666)) == -1)
    my_putstderr("Open: dest fail\n");
  get_champ(champ, tmp);
  write_prog(dest, tmp, champ);
  free_end(tmp, fd, dest, champ);
  return (0);
}
