/*
** parameter.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:23 2015 Manuel Trambert
** Last update Sat Apr 11 04:40:00 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "op.h"

int	count_size(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ',')
	nb += 1;
      i += 1;
    }
  return (nb);
}

char	*kill_space(char *str)
{
  int	i;
  int	e;
  char	*tmp;

  i = 0;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i] != '\0')
    {
      if (str[i] == ' ' && (str[i - 1] == ','
			    || str[i - 1] == ' ' || str[i + 1] == ','))
	i += 1;
      else
	{
	  tmp[e] = str[i];
	  e += 1;
	  i += 1;
	}
    }
  tmp[e] = '\0';
  return (tmp);
}

void	init_cut_parameter(int *e, int *i, int *nb)
{
  *i = -1;
  *e = 0;
  *nb = 0;
}

char	**cut_parameter(char *str)
{
  int	i;
  int	e;
  int	nb;
  char	**parameter;

  init_cut_parameter(&e, &i, &nb);
  if ((parameter = malloc(sizeof(*parameter) * (count_size(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  if ((parameter[nb] = malloc(sizeof(**parameter) * my_strlen(str))) == NULL)
    exit(EXIT_FAILURE);
  while (str[++i] != '\0')
    {
      if (str[i] == ',' && (i += 1))
	{
	  parameter[nb++][e] = '\0';
	  e = 0;
	  if ((parameter[nb] =
	       malloc(sizeof(**parameter) * my_strlen(str))) == NULL)
	    exit(EXIT_FAILURE);
	}
      parameter[nb][e++] = str[i];
    }
  parameter[nb++][e] = '\0';
  parameter[nb] = NULL;
  return (parameter);
}
