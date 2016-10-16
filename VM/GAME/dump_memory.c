/*
** dump_memory.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Apr 12 05:04:01 2015 KASO soto
** Last update Sun Apr 12 17:07:15 2015 KASO soto
*/

#include "vm.h"

int     my_putnbr_base_dump(int nbr, char *base, int *count)
{
  int   result;
  int   div;
  int   size_base;

  div = 1;
  size_base = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  while (nbr / div >= size_base)
    div *= size_base;
  while (div > 0)
    {
      result = (nbr / div) % size_base;
      my_putchar(base[result]);
      if ((*count)++ == 32)
	{
	  *count = 0;
	  my_putchar('\n');
	}
      div /= size_base;
    }
  return (0);
}

void	dump_memory(unsigned char *mem)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (i < MEM_SIZE)
    {
      my_putnbr_base_dump(mem[i], "0123456789ABCDEF", &count);
      i++;
    }
  exit(EXIT_SUCCESS);
}

void	incr_var_game(int *a, int *b)
{
  (*a)++;
  (*b)++;
}
