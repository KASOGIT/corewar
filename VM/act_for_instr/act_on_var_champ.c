/*
** act_on_var_champ.c for  in /home/soto_a/rendu/Corewar/act_for_instr
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Apr  3 19:10:25 2015 KASO soto
** Last update Sun Apr 12 18:06:03 2015 Kévin Julien
*/

#include "vm.h"

void    incr_pc(t_list *champ, int size)
{
  int   i;

  i = 1;
  while (i < size + 1)
    {
      champ->champ.pc++;
      if (champ->champ.pc == MEM_SIZE)
        champ->champ.pc = 0;
      i++;
    }
}
