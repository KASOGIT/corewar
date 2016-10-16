/*
** epur.c for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Fri Apr  3 11:58:43 2015 Manuel Trambert
** Last update Fri Apr  3 11:58:43 2015 Manuel Trambert
*/

#include <stdlib.h>
#include "my.h"

char    *epur_str(char *str)
{
  int   i;
  int   e;
  char  *tmp;

  i = -1;
  e = 0;
  while ((str[++i] == ' ' && str[i] == '\t') && str[i] != '\0');
  if (i == my_strlen(str))
    return (NULL);
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 5))) == NULL)
    exit(1);
  while (str[i] != '\0' && str[i] != ';')
    if ((str[i] == ' ' || str[i] == '\t')
        && ((str[i + 1] == ' ' || str[i + 1] == '\t') || str[i + 1] == '\0'))
      i += 1;
    else
      {
        tmp[e] = (str[i] == '\t') ? ' ' : str[i];
        e += 1;
        i += 1;
      }
  tmp[e] = '\0';
  if (tmp[0] == ' ')
    return (tmp + 1);
  return (tmp);
}

