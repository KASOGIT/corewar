/*
** write_prog.c for corewar in /home/julien_k/CPE_2014_corewar/ASM/src
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Fri Apr  3 16:13:35 2015 Kévin Julien
** Last update Sat Apr 11 04:23:38 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "op.h"

void	write_head(int dest, t_tmp *tmp)
{
  int	deg;

  deg = 0;
  if (litle_endian() == 1)
    {
      tmp->head->magic = litle_to_big(tmp->head->magic);
      tmp->head->prog_size = litle_to_big(tmp->head->prog_size);
    }
  write(dest, &(tmp->head->magic), sizeof(int));
  write(dest, tmp->head->prog_name, PROG_NAME_LENGTH);
  write(dest, &deg, 4);
  write(dest, &(tmp->head->prog_size), sizeof(int));
  write(dest, tmp->head->comment, COMMENT_LENGTH);
  write(dest, &deg, 4);
}

void		write_cmd(char *str, int dest, t_champ *champ)
{
  int		i;
  char		**tmp;
  char		*nospace;
  static int	octet = 1;

  i = 0;
  nospace = kill_space(str);
  tmp = my_str_to_wordtab(nospace);
  while (g_name_func[i].name != NULL
	 && my_strncmp(str, g_name_func[i].name,
		       my_strlen(g_name_func[i].name)) != 0)
    i += 1;
  if (g_name_func[i].name == NULL)
    exit(EXIT_FAILURE);
  g_name_func[i].name_fct(dest, tmp, &octet, champ);
  free(nospace);
  free(tmp);
}

void		write_label(t_champ *champ, int dest)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = champ;
  while (tmp != NULL)
    {
      while (tmp->label[i] != NULL)
	{
	  write_cmd(tmp->label[i], dest, champ);
	  i += 1;
	}
      tmp = tmp->next;
      i = 0;
    }
}

void	write_prog(int dest, t_tmp *tmp, t_champ *champ)
{
  write_head(dest, tmp);
  write_label(champ, dest);
}
