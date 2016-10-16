/*
** my.h for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Mon Dec 22 08:19:55 2014 Manuel Trambert
** Last update Sun Apr 12 18:21:47 2015 Manuel Trambert
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

# define UP		65
# define DOWN		66
# define RIGHT		67
# define LEFT		68
# define ECHAP		27
# define ENTER		10
# define SPACE		32
# define BACKSPACE	127
# define DEL		27

#include <dirent.h>
#include <term.h>
#include "my.h"

typedef struct	s_list
{
  char		*name;
  int		line;
  int		pass;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_pos
{
  int	del;
  char	*path;
  char	**av;
  int	space;
  int	draw;
  char	**table;
  int	bool;
  int	nb;
  int	resize;
  int	cpt;
  int	curs;
  int	i;
  int	tty;
  int	sizex;
  int	sizey;
  int	sizecol;
  int	sizeline;
  int	pos_x;
  int	pos_y;
  int	open;
  char	*str;
}		t_pos;

typedef struct s_glob
{
  t_list	*ptr;
  t_list	*end;
  t_pos		*pos;
  int		flag;
  struct termios tmp;
}		t_glob;

extern t_glob	g_glob;

void		add_node(t_list **ptr, t_pos *pos);
void		draw_number(t_pos *pos);
void		move_curs(t_pos *pos, t_list *ptr, char *str, t_list *end);
void		draw_line(t_pos *pos);
void		draw_side(t_pos *pos);
int		search_str(char *str, t_list *ptr, t_list *end);
void		draw_pipe(t_pos *pos, int x, int y);
void		draw_back(t_pos *pos, int x, int y);
char		*my_strcopy(char *buffer, char *str);
int		my_strcmp(char *str, char *str2);
int		my_search(t_pos *pos, t_list *ptr, t_list *end);
void		draw_around(t_pos *pos);
void		finish_select();
void		draw_side(t_pos *pos);
int		reset_term(t_pos *pos);
int		set_buff(char *str, t_list **ptr, t_list **end, t_pos *pos);
int		get_curs(t_pos *pos, t_list *ptr);
void		move_right(t_pos *pos);
void		move_left(t_pos *pos);
void		move_up(t_pos *pos);
void		move_down(t_pos *pos);
int		unset_curs(t_pos *pos);
int		my_size(t_pos *pos, t_list *end, t_list *ptr);
int		my_putc(int e);
void		*xmalloc(int n);
void		my_putttychar(char e);
int		set_list(char **str, t_list **ptr, t_list **end, t_pos *pos);
void		my_putttystr(char *str);
void		set_pass(t_list *ptr, t_pos *pos);
void		del_node(t_list **ptr, t_list **end, t_pos *pos);
int		disp_list(t_list *ptr, t_list *end, t_pos *pos);
int		get_move(char buffer[2], t_pos *pos, t_list *end, t_list *ptr);
int		init_pos(t_list *ptr, t_list *end, t_pos *pos);
char		*my_strdup(char	*str);
DIR		*xopendir(char *str);
void		resize();
void		raw_mode(t_pos *pos);
void		select_arg(t_list *ptr, t_list *end, t_pos *pos);
int		end_my_select(t_list *ptr, t_pos *pos, t_list *end);
char		**fill_tab(char **board);
char		*set_path(char *path, char *str);
t_list		*get_ptr(t_list *ptr, t_list *end);
char		*unset_path(char *str);
int		disp_end(t_list *ptr, t_pos *pos);

#endif /* !MY_SELECT_H_ */
