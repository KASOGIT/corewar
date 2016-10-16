/*
** my_fork.c for my_fork in /home/soto_a/rendu/Corewar/instructions
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Apr  1 15:50:18 2015 KASO soto
** Last update Sun Apr 12 18:14:35 2015 Kévin Julien
*/

#include "vm.h"

int	*copy_reg(int *reg)
{
  int	i;
  int	*new_reg;

  i = 0;
  if ((new_reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    exit(EXIT_FAILURE);
  while (i < REG_NUMBER)
    {
      new_reg[i] = reg[i];
      i++;
    }
  return (new_reg);
}

void	copy_prog_name(char *prog_name, header_t *header)
{
  int	i;

  i = 0;
  while (prog_name[i])
    {
      header->prog_name[i] = prog_name[i];
      i++;
    }
}

int		my_fork(t_corewar *corewar, t_list *champ)
{
  t_champ	new_champ;
  short		value;

  champ->champ.start_pc = champ->champ.pc;
  incr_pc(champ, sizeof(char));
  value = get_short_from_string(corewar->mem, champ->champ.pc);
  incr_pc(champ, sizeof(short));
  new_champ.pc = get_pos(champ->champ.start_pc, value % IDX_MOD);
  new_champ.alive = 0;
  new_champ.delay = 0;
  new_champ.prog_number = champ->champ.prog_number;
  new_champ.reg = copy_reg(champ->champ.reg);
  copy_prog_name(champ->champ.header.prog_name, &(new_champ.header));
  new_champ.carry = 0;
  my_put_in_list(&(corewar->champs), new_champ, 0);
  champ->champ.delay = op_tab[11].nbr_cycles;
  return (0);
}
