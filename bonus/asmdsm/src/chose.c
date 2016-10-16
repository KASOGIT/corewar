/*
** chose.c for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 17:18:34 2015 Manuel Trambert
** Last update Sun Apr 12 20:49:46 2015 Manuel Trambert
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*get_name_file_cor(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i] != '.')
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[i] = str[i];
  tmp[i + 1] = 's';
  tmp[i + 2] = '\0';
  return (tmp);
}

void		write_prog_dsm(int fd, int dest, header_t header)
{
  unsigned char	str[4096];
  int		nb;
  int		i;

  if (read(fd, str, header.prog_size) < 0)
    exit(EXIT_FAILURE);
  str[header.prog_size] = '\0';
  i = -1;
  while (++i <= header.prog_size)
    {
      nb = 0;
      while (g_dsm_func[nb].name != NULL
	     && str[i] != g_dsm_func[nb].type)
	nb += 1;
      if (g_dsm_func[nb].name != NULL)
	{
	  my_putstr(g_dsm_func[nb].name, dest);
	  my_putchar('\t', dest);
	  if (g_dsm_func[nb].loop == -1)
	    my_putchar('%', dest);
	  i = g_dsm_func[nb].type_fct(str, &i, g_dsm_func[nb].loop, dest);
	  if (g_dsm_func[nb].loop <= 0 && g_dsm_func[nb].loop != -2)
	    my_putchar('\n', dest);
	}
    }
}

int	check_cor_name(char *str)
{
  if (my_strncmp(str + (my_strlen(str) - 4), ".cor", 4) != 0)
    return (0);
  return (1);
}

int	desassembleur(char *src, header_t header)
{
  int		fd;
  int		dest;

  if (check_cor_name(src) == 0)
    my_putstderr("Error: invalid name file\n");
  open_file(&fd, &dest, src);
  if ((read(fd, &header, sizeof(header_t))) < 0)
    my_putstderr("Invalid file: Empty\n");
  my_putstr(".name\t", dest);
  my_putchar('"', dest);
  my_putstr(header.prog_name, dest);
  my_putchar('"', dest);
  my_putchar('\n', dest);
  my_putstr(".comment\t", dest);
  my_putchar('"', dest);
  my_putstr(header.comment, dest);
  my_putchar('"', dest);
  my_putstr("\n\n", dest);
  if (litle_endian())
    header.prog_size = litle_to_big(header.prog_size);
  write_prog_dsm(fd, dest, header);
  return (0);
}

int	after_sdl(__attribute__((unused))int ac, char *file, int flag)
{
  header_t	header;

  header.magic = 0;
  my_bzero(header.prog_name, PROG_NAME_LENGTH + 1);
  header.prog_size = 0;
  my_bzero(header.comment, COMMENT_LENGTH + 1);
  if (file == NULL)
    my_putstr("./asm flag (-d) file.cor or (-a) file.s Usage: --help\n", 2);
  if (flag == 1)
    assembleur(file);
  else if (flag == 0)
    desassembleur(file, header);
  exit(0);
}
