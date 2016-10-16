/*
** get.c for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 17:20:04 2015 Manuel Trambert
** Last update Sun Apr 12 17:20:04 2015 Manuel Trambert
*/

#include "my.h"

int		get_size_oct(unsigned char *str, int *pc, int loop, int fd)
{
  unsigned char	*byte_code;
  int		nb;
  int		e;
  int		i;

  i = (*pc);
  nb = 0;
  e = 0;
  i += 1;
  byte_code = get_byte_code(str, i);
  while (nb < loop)
    {
      if (byte_code[e] == 0 && byte_code[e + 1] == 1)
      	print_register(str, &i, fd);
      else if (byte_code[e] == 1 && byte_code[e + 1] == 1)
	print_dir(str, &i, 0, fd);
      else if (byte_code[e] == 1 && byte_code[e + 1] == 0)
	print_ind(str, &i, 0, fd);
      e += 2;
      nb += 1;
      if (nb < loop)
	my_putchar(',', fd);
    }
  my_putchar('\n', fd);
  return (i);
}

int		get_size_ldi(unsigned char *str,
			     int *pc, __attribute__((unused))int loop, int fd)
{
  unsigned char	*byte_code;
  int		i;

  i = (*pc);
  i += 1;
  byte_code = get_byte_code(str, i);
  if (byte_code[0] == 0 && byte_code[1] == 1)
    print_register(str, &i, fd);
  else
    {
      my_putchar('%', fd);
      print_dir(str, &i, 0, fd);
    }
  my_putchar(',', fd);
  if (byte_code[2] == 0 && byte_code[3] == 1)
    print_register(str, &i, fd);
  else
    {
      my_putchar('%', fd);
      print_dir(str, &i, 0, fd);
    }
  my_putchar(',', fd);
  print_register(str, &i, fd);
  my_putchar('\n', fd);
  return (i);
}

int		get_size_sti(unsigned char *str, int *pc,
			     __attribute__((unused))int loop, int fd)
{
  unsigned char	*byte_code;
  int		i;

  i = (*pc);
  i += 1;
  byte_code = get_byte_code(str, i);
  print_register(str, &i, fd);
  my_putchar(',', fd);
  if (byte_code[2] == 0 && byte_code[3] == 1)
    print_register(str, &i, fd);
  else
    {
      my_putchar('%', fd);
      print_dir(str, &i, 0, fd);
    }
  my_putchar(',', fd);
  if (byte_code[4] == 0 && byte_code[5] == 1)
    print_register(str, &i, fd);
  else
    {
      my_putchar('%', fd);
      print_dir(str, &i, 0, fd);
    }
  my_putchar('\n', fd);
  return (i);
}
