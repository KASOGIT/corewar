/*
** main.c for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 17:20:09 2015 Manuel Trambert
** Last update Sun Apr 12 19:57:18 2015 Manuel Trambert
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "my_select.h"
#include "my.h"

t_glob	g_glob;

void	gere_key(SDL_Event event)
{
  char	**av;

  av = my_str_to_wordtab("./asm .");
  if (event.key.keysym.sym == SDLK_ESCAPE)
    exit(0);
  else if (event.key.keysym.sym == SDLK_UP)
    {
      g_glob.flag = 1;
      my_sdl("Pictures/Compilateur.jpg");
    }
  else if (event.key.keysym.sym == SDLK_DOWN)
    {
      g_glob.flag = 0;
      my_sdl("Pictures/lol.jpg");
    }
  else if (event.key.keysym.sym == SDLK_BACKSPACE)
    {
      SDL_Quit();
      my_select(2, av);
    }
}

void		pause()
{
  int		continuer;
  SDL_Event	event;

  continuer = 1;
  while (continuer != 0)
    {
      SDL_PollEvent(&event);
      if (event.active.type)
	gere_key(event);
    }
}

void	my_sdl(char *str)
{
  SDL_Surface	*ecran;
  SDL_Surface	*imageDeFond;
  SDL_Rect	positionFond;

  ecran = NULL;
  imageDeFond = NULL;
  positionFond.x = 0;
  positionFond.y = 0;
  if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
    exit(0);
  SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
  ecran = SDL_SetVideoMode(2000, 1500, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
  if ((imageDeFond = IMG_Load(str)) == NULL)
    exit(EXIT_FAILURE);
  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
  SDL_Flip(ecran);
  pause();
  SDL_FreeSurface(imageDeFond);
  SDL_Quit();
}

int	main(__attribute__((unused))int ac, char **av)
{
  g_glob.flag = 0;
  if (ac == 2)
    {
      if (my_strcmp(av[1], "--help") != 0)
	print_help(av[2]);
    }
  else
    my_sdl("Pictures/Compilateur.jpg");
  return (0);
}
