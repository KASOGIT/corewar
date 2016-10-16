/*
** graph_s.h for corewar in /home/marcot_f/Desktop/CPE_2014_corewar3/soto_wooork
** 
** Made by Felix Marcotte
** Login   <marcot_f@epitech.net>
** 
** Started on  Sun Apr 12 05:58:21 2015 Felix Marcotte
** Last update Sun Apr 12 19:50:56 2015 Felix Marcotte
*/

#ifndef GRAPH_S_H_
# define GRAPH_S_H_

typedef struct  s_colorfont
{
  SDL_Color     white;
  SDL_Color     red;
}               t_color;

typedef struct  s_casepos
{
  int		pos;
  int		is_color;
}              t_cp;

typedef struct		s_listarena
{
  t_cp			infopos;
  struct s_listarena	*next;
}			t_listarena;

typedef struct  s_window
{
  SDL_Window    *window;
  SDL_Surface   *screen;
  SDL_Renderer  *renderer;
  SDL_Texture   *texture;
  TTF_Font      *fonts;
  t_color       *color;
}               t_win;

#endif	/* GRAPH_S_H_ */
