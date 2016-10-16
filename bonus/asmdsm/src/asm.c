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

int	assembleur(char *src)
{
  t_tmp		*tmp;
  int		fd;
  t_champ	*champ;
  int		dest;

  if ((champ = malloc(sizeof(*champ))) == NULL)
    return (-1);
  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  if ((tmp->head = malloc(sizeof(header_t))) == NULL)
    return (-1);
  tmp->print = champ;
  init_champ(champ, tmp);
  if ((fd = open(src, O_RDONLY)) == -1)
    my_putstderr("Open: source fail\n");
  parsing(fd, champ, tmp);
  if ((dest = open(get_name_file(src), O_RDWR | O_CREAT | O_TRUNC,
		   0666)) == -1)
    my_putstderr("Open: dest fail\n");
  get_champ(champ, tmp);
  write_prog(dest, tmp, champ);
  free_end(tmp, fd, dest, champ);
  return (0);
}
