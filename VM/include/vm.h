/*
** vm.h for vm in /home/soto_a/rendu/Corewar/include
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar 23 13:02:26 2015 KASO soto
** Last update Sun Oct 16 15:55:19 2016 
*/

#ifndef VM_H_
# define VM_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "op.h"
#include "linked_list.h"

# define NBR_INSTR	16

struct			s_champ
{
  int			alive;
  header_t		header;
  int			delay;
  int			prog_number;
  int			*reg;
  int			pc;
  int			start_pc;
  int			carry;
  unsigned char		prog[4096];
  int			mem_size[2];
};

struct			s_list
{
  struct s_champ        champ;
  struct s_list         *prev;
  struct s_list         *next;
};

struct			s_corewar
{
  t_list		*champs;
  unsigned char		mem[MEM_SIZE];
  int			nb_cycle_bef_end;
  int			nb_champ;
  int			nb_live;
};

struct		s_parsing_arg
{
  t_champ	champ;
  int		i;
  int		nb_champ;
  int		start;
  int		count_param;
};

typedef struct		s_ptr_func
{
  unsigned char		id_cmd;
  int			(*ptr_func)(t_corewar *corewar, t_list *champ);
}			t_ptr_func;

extern	t_ptr_func	g_tab_func[];

void		my_usage();
void		incr_var_game(int *a, int *b);
void		dump_memory(unsigned char *mem);
void		reset_alive(t_list **champs);
void		delete_dead_champ(t_list **champs);
void		who_win(t_list **champs);
int		get_value_reg(t_corewar *corewar, t_list *champ, int num_instr);
int		my_putnbr_base_dump(int nbr, char *base, int *count);
int		my_put_error(char *explain, int mode, t_list *champ, int num_instr);
int		get_values_instr(t_corewar *corewar, t_list *champ,
				 unsigned char *byte_code, int num_instr);
int		get_values_instr_spec(t_corewar *corewar, t_list *champ,
				      unsigned char *byte_code, int num_instr);
unsigned char	*get_string_from_int(int value);
int		set_result_lldi(t_corewar *corewar, t_list *champ, unsigned char *byte_code, int value);
int		set_result_ldi(t_corewar *corewar, t_list *champ, unsigned char *byte_code, int value);
int		*copy_reg(int *reg);
void		copy_prog_name(char *prog_name, header_t *header);
int		get_pos(int pc, int pos);
void            load_value_to_mem_adress_dir(t_corewar *corewar, int value, int pos);
void            load_value_to_mem_adress_ind(t_corewar *corewar, t_list *champ, int value, short pos);
int		litle_endian();
int		litle_to_big(int magic);
short		litle_to_big_short(short value);
int		verif_and_get_cycle_bef_end(char *data);
void		check_arg_and_set_value(char **av, t_parsing_arg *pars);
void		read_and_check_info_champ(t_champ *champ, char *path_name);
void		init_champ(t_champ *champ);
int		check_and_get_prog_number(char *new_prog_nb, int old_prog_nb);
int		*init_mem_per_champ(int nb_champ, int *start);
void		get_size_and_init_prog(t_champ *champ, int fd_champ);
int		check_and_set_start_mem(char *nb);
int		count_nb_champ(char **av);
void		init_var_pars(t_parsing_arg *pars, char **av);
void		reset_var_pars(t_parsing_arg *pars);
void		control_champ_load(t_list **champs, int nb_champ);
void		control_mem_placement(t_list **champs);
void		control_total_size_champs(t_list **champs);
void		run_game(t_corewar *corewar);
int		is_alive(t_list **champs);
void		init_mem(t_corewar *corewar);
void		load_champ_in_memory(t_corewar *corewar);
int		count_in_live(t_list **champs);
void		run_instructions(t_corewar *corewar);
int		get_int_from_string(unsigned char *str, int pc);
short		get_short_from_string(unsigned char *mem, int pc);
unsigned char	*get_str_in_mem(unsigned char *mem, int pc, int size);
void		incr_pc(t_list *champ, int size);
unsigned char	*get_byte_code(unsigned char *mem, int pc);
void		load_value_to_reg_ind(t_corewar *corewar, t_list *champ, int value, int num_reg);
void		load_value_to_reg_dir(t_list *champ, int value, int num_reg);
int		my_live(t_corewar *corewar, t_list *champ);
int		my_ld(t_corewar *corewar, t_list *champ);
int		my_st(t_corewar *corewar, t_list *champ);
int		my_add(t_corewar *corewar, t_list *champ);
int		my_sub(t_corewar *corewar, t_list *champ);
int		my_and(t_corewar *corewar, t_list *champ);
int		my_or(t_corewar *corewar, t_list *champ);
int		my_xor(t_corewar *corewar, t_list *champ);
int		my_zjmp(t_corewar *corewar, t_list *champ);
int		my_ldi(t_corewar *corewar, t_list *champ);
int		my_sti(t_corewar *corewar, t_list *champ);
int		my_fork(t_corewar *corewar, t_list *champ);
int		my_lld(t_corewar *corewar, t_list *champ);
int		my_lldi(t_corewar *corewar, t_list *champ);
int		my_lfork(t_corewar *corewar, t_list *champ);
int		my_aff(t_corewar *corewar, t_list *champ);
int		main(int ac, char **av);

#endif /* !VM_H_ */
