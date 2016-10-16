/*
** string_error.h for  in /home/trambe_m/CPE_2014_corewar/bonus/asmdsm/include
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun Apr 12 18:22:03 2015 Manuel Trambert
** Last update Sun Apr 12 18:24:13 2015 Manuel Trambert
*/

#ifndef STRING_ERROR_PARAM_H_
# define STRING_ERROR_PARAM_H_

static char	*g_string_param_err[][5] =
  {
    {"live", "direct", NULL, NULL, NULL},
    {"ld", "direct or an indirect", "register or a direct", NULL, NULL},
    {"st", "register", "indirect or a register", NULL, NULL},
    {"add", "register", "register", "register", NULL},
    {"sub", "register", "register", "register", NULL},
    {"and", "register or a direct or an indirect",
     "register or a direct or an indirect", "register", NULL},
    {"or", "register or a direct or an indirect",
     "register or a direct or an indirect", "register", NULL},
    {"xor", "register or a direct or an indirect",
     "register or a direct or an indirect", "register", NULL},
    {"zjmp", "direct", NULL, NULL, NULL},
    {"ldi", "register or a direct or an indirect", "direct or a register",
     "register", NULL},
    {"sti", "register", "register or a direct or an indirect",
     "direct or a register", NULL},
    {"fork", "direct", NULL, NULL, NULL},
    {"lld", "direct or indirect", "register", NULL, NULL},
    {"lldi", "register or a direct or an indirect", "director or a register",
     "register", NULL},
    {"lfork", "direct", NULL, NULL, NULL},
    {"aff", "register", NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL}
  };

#endif /* !STRING_ERROR_PARAM_H_ */
