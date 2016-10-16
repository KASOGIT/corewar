/*
** linkedlist.h for linked_list.h in /home/soto_a/rendu/PSU_2014_minishell1/myshll
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Jan 20 19:10:23 2015 Kaso Soto
** Last update Mon Mar 30 19:16:55 2015 KASO soto
*/

#ifndef LINKED_LIST_H_
# define LINKED_LIST_H_

typedef struct s_corewar	t_corewar;
typedef struct s_parsing_arg	t_parsing_arg;
typedef struct s_list		t_list;
typedef struct s_champ		t_champ;

void    my_init_list(t_list **list);
void    my_put_in_list(t_list **list, t_champ champ, int choice);
void    my_free_list(t_list **list);
void    my_create_list(t_corewar *corewar, char **data);
void    my_delete_elem(t_list *list);
void    my_delete_on_edges(t_list *list, int choice);
void    my_show_list(t_list *list, int direction);
int     my_size_list(t_list *list);

#endif /* !LINKED_LIST_H_ */
