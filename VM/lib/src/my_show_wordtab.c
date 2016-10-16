/*
** my_show_wordtab.c for my_show_wordtab.c in /home/soto_a/rendu/Piscine_C_J08/ex_05
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Oct 10 10:58:02 2014 adam kaso
** Last update Fri Dec  5 14:53:18 2014 Kaso Soto
*/

#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}
