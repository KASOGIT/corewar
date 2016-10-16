/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/soto_a/rendu/Piscine_C_J08
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Thu Oct  9 15:23:36 2014 adam kaso
** Last update Sun Mar  8 19:03:15 2015 KASO soto
*/

#include <stdlib.h>
#include "my.h"

int	my_char_is_print(char e)
{
  if (e > 32 && e <= 126)
    return (1);
  return (0);
}

int	my_strword(char *str)
{
  int	i;
  int	w;

  i = 0;
  w = 0;
  while (str[i] != '\0')
    {
      if (my_char_is_print(str[i]) == 1)
	{
	  w++;
	  while (my_char_is_print(str[i]) == 1)
	    i++;
	}
      else
	i++;
    }
  return (w);
}

void	my_init(int *i, int *c, int *charac)
{
  *i = 0;
  *c = 0;
  *charac = 0;
}

void	my_alloc_cpy_set(char **s1, char *s2, int *n, int *i)
{
  if ((*s1 = malloc(sizeof(char) * (*n + 1))) == NULL)
    exit(EXIT_FAILURE);
  my_strncpy(*s1, s2, *n);
  *n = 0;
  (*i)++;
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	c;
  int	charac;
  char	**ptr_char;

  my_init(&i, &c, &charac);
  if ((ptr_char = malloc(sizeof(char*) * (my_strword(str) + 1))) == NULL)
    return (NULL);
  while (i < my_strword(str))
    {
      if (my_char_is_print(str[c]) == 1)
	{
	  while (my_char_is_print(str[c]) == 1)
	    {
	      c += 1;
	      charac += 1;
	    }
	  my_alloc_cpy_set(&ptr_char[i], &str[c - charac], &charac, &i);
	}
      else
	c++;
    }
  ptr_char[i] = 0;
  return (ptr_char);
}
