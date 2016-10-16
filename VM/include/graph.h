/*
** graph.h for corewar in /home/marcot_f/Desktop/CPE_2014_corewar3/soto_wooork
** 
** Made by Felix Marcotte
** Login   <marcot_f@epitech.net>
** 
** Started on  Sun Apr 12 05:54:57 2015 Felix Marcotte
** Last update Sun Apr 12 20:21:33 2015 Felix Marcotte
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# define SIZE_X 1248
# define SIZE_Y 720

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graph_s.h"

typedef struct	s_corewar t_corewar;

/* Init_SDL.c */
void		init_win(t_win *);
void		load_media(t_win *);
void		close_sdl(t_win *);
void		gere_event(t_win *);
/* SDL_Function.c */
SDL_Rect	set_position(int, int, int, int);
char		*nbr_to_char(int);
/* load_entity.c */
void		aff_name(t_champ, t_win *, SDL_Rect );
void		load_name(t_corewar *, t_win *);
void		aff_case(t_win *, int, SDL_Rect, SDL_Surface *);
void		load_case(t_corewar *, t_win *);
/* Load_Arena.c */
int		is_color(t_win *, int, int);
void		aff_arena(int, t_corewar *, t_win *, SDL_Rect);
void		load_arena(t_win *, t_corewar *);

#endif	/* GRAPH_H_ */
