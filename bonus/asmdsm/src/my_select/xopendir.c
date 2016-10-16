/*
** xopendir.c for  in /home/trambe_m/My_select
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Thu Jan  8 07:13:30 2015 Manuel Trambert
** Last update Sun Jan 11 13:54:54 2015 Manuel Trambert
*/

#include <dirent.h>
#include <unistd.h>

DIR	*xopendir(char *str)
{
  DIR	*buffer;

  if ((buffer = opendir(str)) == NULL)
    {
      write(2, "No directory\n", 14);
      return (NULL);
    }
  return (buffer);
}
