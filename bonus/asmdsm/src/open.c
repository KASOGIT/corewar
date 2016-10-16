/*
** open.c for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 17:21:22 2015 Manuel Trambert
** Last update Sun Apr 12 17:22:08 2015 Manuel Trambert
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	open_file(int *fd, int *dest, char *src)
{
  if ((*fd = open(src, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  if ((*dest = open(get_name_file_cor(src), O_RDWR | O_CREAT
		   | O_TRUNC, 0666)) == -1)
    exit(EXIT_FAILURE);
}
