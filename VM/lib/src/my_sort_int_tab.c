/*
** my_sort_int_tab.c for my_sort_int_tab.c in /home/soto_a/rendu/Piscine_C_J04
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 13:47:26 2014 adam kaso
** Last update Wed Mar 11 23:05:43 2015 KASO soto
*/

#include "my.h"

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	tmp;

  i = 0;
  while (i < size - 1)
    {
      if (tab[i] > tab[i + 1])
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  i = 0;
	}
      else
	{
	  i++;
	}
    }
}
