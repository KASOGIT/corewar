/*
** get_pos.c for  in /home/soto_a/rendu/TMP/CPE_2014_corewar/soto_wooork/act_for_instr
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Apr 10 23:23:02 2015 KASO soto
** Last update Fri Apr 10 23:23:07 2015 KASO soto
*/

#include "vm.h"

int	get_pos(int pc, int forward)
{
  int	i;

  i = 0;
  while (i < forward)
    {
      i += 1;
      pc += 1;
      if (pc == MEM_SIZE)
	pc = 0;
    }
  return (pc);
}
