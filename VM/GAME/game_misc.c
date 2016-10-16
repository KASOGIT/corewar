/*
** game_misc.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/GAME
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Apr 12 15:29:29 2015 KASO soto
** Last update Sun Apr 12 15:31:23 2015 KASO soto
*/

#include "vm.h"

int             is_alive(t_list **champs)
{
  int           count;
  t_list        *tmp;

  count = 0;
  tmp = (*champs)->next;
  while (tmp != *champs)
    {
      if (tmp->champ.alive == 1)
        count++;
      tmp = tmp->next;
    }
  return (count > 1 ? 1 : 0);
}

int             count_in_live(t_list **champs)
{
  int           count;
  t_list        *tmp;

  count = 0;
  tmp = (*champs)->next;
  while (tmp != *champs)
    {
      if (tmp->champ.alive == 1)
        count++;
      tmp = tmp->next;
    }
  return (count);
}

void            delete_dead_champ(t_list **champs)
{
  t_list        *tmp;

  tmp = (*champs)->next;
  while (tmp != *champs)
    {
      if (tmp->champ.alive == 0)
        {
          my_delete_elem(tmp);
          tmp = (*champs)->next;
        }
      else
        tmp = tmp->next;
    }
}

void            who_win(t_list **champs)
{
  t_list        *tmp;

  tmp = (*champs)->next;
  while (tmp != *champs)
    {
      if (tmp->champ.alive == 1)
        {
          my_putstr("Joueur ");
          my_put_nbr(tmp->champ.prog_number);
          my_putchar('(');
          my_putstr(tmp->champ.header.prog_name);
          my_putstr(") à gagné\n");
        }
      tmp = tmp->next;
    }
}

void            reset_alive(t_list **champs)
{
  t_list        *tmp;

  tmp = (*champs)->next;
  while (tmp != (*champs))
    {
      if (tmp->champ.alive == 1)
        tmp->champ.alive = 0;
      tmp = tmp->next;
    }
}
