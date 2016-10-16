/*
** display_on_list.c for display_on_list in /home/soto_a/rendu/CPE_2014_Pushswap
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Dec 13 18:17:55 2014 Kaso Soto
** Last update Sun Mar 29 15:32:32 2015 KASO soto
*/

#include "vm.h"

void		my_show_list(t_list *list, int direction)
{
  t_list	*tmp;

  if (direction == 0)
    {
      tmp = list->next;
      while (tmp != list)
        {
	  my_putchar('\n');
          tmp = tmp->next;
        }
    }
  else
    {
      tmp = list->prev;
      while (tmp != list)
        {
	  my_putchar('\n');
          tmp = tmp->prev;
        }
    }
}
