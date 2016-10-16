/*
** my.h for  in /home/trambe_m/trash/CPE_2014_corewar/ASM/include
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sat Apr  4 20:43:36 2015 Manuel Trambert
** Last update Sat Apr 11 05:04:09 2015 Manuel Trambert
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include "op.h"

typedef struct		s_champ
{
  char			*name;
  char			**label;
  int			adress;
  struct s_champ	*next;
}			t_champ;

typedef struct		s_tmp
{
  int			size;
  char			**text;
  header_t		*head;
  t_champ		*print;
}			t_tmp;

typedef struct		s_type_func
{
  int			type;
  int			(*type_fct)(char *str, int line, char **text, int bool);
}			t_type_func;

typedef struct		s_name_func
{
  char			*name;
  void			(*name_fct)(int dest,
				    char **tmp, int *octet, t_champ *champ);
}			t_name_func;

typedef struct		s_cmd
{
  char			*name;
  int			ret;
}			t_cmd;

extern	t_cmd		g_cmd[];
extern	t_name_func	g_name_func[];
extern	t_type_func	g_type_func[];

/* init.c */
void	init_champ(t_champ *champ, t_tmp *tmp);
void	init_get_label(int *e, int *i, t_champ **champ, char **text);

/* check_type.c */
int	check_reg_dir(char *str, int line, char **text, int bool);
int	check_reg_ind(char *str, int line, char **text, int bool);
int	check_dir_ind(char *str, int line, char **text, int bool);
int	check_everytype(char *str, int line, char **text, int bool);
int	check_index(char *str);

/* error.c */
int	check_header(int fd);

/* label.c */
int	param_islabel(char *str);
int	check_label(char *str);
int	labelexist(char *str, char **text);
int	size_new_label(char **text, int i);

/* parsing.c */
int	check_syntax(char **tab, int line, char **text);

/* free.c */
void	free_end(t_tmp *tmp, int fd, int dest, t_champ *champ);
void	free_tab(char **tab);

/* utils.c */
char	*get_name_file(char *str);
void	my_put_nbr(int nb);
void	my_putstderr(char *str);

/* check_arg.c */
int	check_mul_arg(char **tab, int line, char **text, int i);
int	check_arg(char *str, int line, char **text, int type);

/* check_parameter.c */
int	check_reg(char *str, int line, char **text, int bool);
int	check_ind(char *str, int line, char **text, int bool);
int	check_dir(char *str, int line, char **text, int bool);

/* header.c */
void	get_name(char *str, t_tmp *ptr);
int	get_comment(char *str, t_tmp *ptr);

/* write_cmd.c */
int	my_get_nbr_core(char *str);
void	write_live(int dest, char **tmp, int *octet, t_champ *champ);
void	write_fork(int dest, char **tmp, int *octet, t_champ *champ);
void	write_zjmp(int dest, char **tmp, int *octet, t_champ *champ);

/* is.c */
int	islabel(char *str);
int	iscmd(char *str);
int	isnum(char *str);

/* size.c */
int	get_champ(t_champ *champ, t_tmp *tmp);

/* fill_list.c */
void	get_label(t_champ **champ, char **text);

/* parameter.c */
char	**cut_parameter(char *str);
char	*kill_space(char *str);

/* size_parameter.c */
int	size_parameter(t_champ *champ);

/* check.c */
int	check_null(char *str);

/* epur.c */
char    *epur_str(char *str);

/* list.c */
void	add_list(t_champ **ptr);

/* my_get_nbr.c */
int	my_get_nbr(char *str);

/* parsing.c */
void	parsing(int fd, t_champ *champ, t_tmp *tmp);

/* my_str_to_wordtab.c */
char	**my_str_to_wordtab(char *str);

/* my_strncmp.c */
int	my_strncmp(char *s1, char *s2, int n);

/* my_strncpy.c */
char	*my_strncpy(char *dest, char *src, int n);

/* tools.c */
char	*my_strdup(char	*str);
int	my_strcmp(char *str, char *str1);
int	my_strlen(const char *str);
void	my_putstr(char *str, int fd);

/* write_prog.c */
void	write_prog(int dest, t_tmp *tmp, t_champ *champ);

/* endian.c */
int	litle_endian();
int	litle_to_big(int nb);
short	litle_to_big_short(short nb);
/* write_* */
void	write_ld(int dest, char **tmp, int *octet, t_champ *champ);
void	write_or(int dest, char **tmp, int *octet, t_champ *champ);
void	write_and(int dest, char **tmp, int *octet, t_champ *champ);
void	write_xor(int dest, char **tmp, int *octet, t_champ *champ);
void	write_ldi(int dest, char **tmp, int *octet, t_champ *champ);
void	write_sti(int dest, char **tmp, int *octet, t_champ *champ);
void	write_lld(int dest, char **tmp, int *octet, t_champ *champ);
void	write_lldi(int dest, char **tmp, int *octet, t_champ *champ);
void	write_lfork(int dest, char **tmp, int *octet, t_champ *champ);
void	write_aff(int dest, char **tmp, int *octet, t_champ *champ);
void	write_sub(int dest, char **tmp, int *octet, t_champ *champ);
void	write_add(int dest, char **tmp, int *octet, t_champ *champ);
void	write_st(int dest, char **tmp, int *octet, t_champ *champ);

#endif /* !MY_H_ */
