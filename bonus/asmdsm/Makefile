##
## Makefile for Makefile
##
## Made by kaso soto
## Login     <soto_a@epitech.net>
##
## Started on 2015
## Last update Sun Apr 12 17:26:11 2015 Manuel Trambert
##

NAME	= asm

SRC	= 	src/main.c \
		src/asm.c \
		src/print_help.c \
		src/open.c \
		src/chose.c \
		src/get.c \
		src/print.c \
		src/read.c \
		src/my_select/chain_list.c \
		src/my_select/disp.c \
		src/my_select/draw.c \
		src/my_select/error.c \
		src/my_select/event.c \
		src/my_select/init.c \
		src/my_select/line.c \
		src/my_select/main.c \
		src/my_select/move.c \
		src/my_select/my_fct.c \
		src/my_select/my_select.c \
		src/my_select/my_tab.c \
		src/my_select/my_tty.c \
		src/my_select/set.c \
		src/my_select/set_list.c \
		src/my_select/tools.c \
		src/my_select/xopendir.c \
		GNL/get_next_line.c \
		src/check_type.c \
		src/endian.c \
		src/utils.c \
		src/func_ptr.c \
		src/check.c \
		src/check_parameter.c \
		src/check_arg.c \
		src/header.c \
		src/error.c \
		src/label.c \
		src/parsing.c \
		src/list.c \
		src/op.c \
		src/my_strncmp.c \
		src/my_strncpy.c \
		src/free.c \
		src/my_str_to_wordtab.c \
		src/my_get_nbr.c \
		src/epur.c \
		src/parameter.c \
		src/size_parameter.c \
		src/is.c \
		src/fill_list.c \
		src/tools.c \
		src/size.c \
		src/init.c \
		src/write_prog.c \
		src/write_cmd.c \
		src/write_sti.c \
		src/write_sub.c \
		src/write_st.c \
		src/write_ld.c \
		src/write_and.c \
		src/write_or.c \
		src/write_xor.c \
		src/write_ldi.c \
		src/write_lld.c \
		src/write_lldi.c \
		src/write_lfork.c \
		src/write_aff.c \

OBJ	= $(SRC:.c=.o)

CFLAGS	= -I./include/ -W -Wall -g3

$(NAME) :$(OBJ)
	 gcc $(OBJ) -o $(NAME) -lSDL -lSDL_image -lncurses

all :	 $(NAME)

clean :
	 rm -f $(OBJ)

fclean : clean
	 rm -f $(NAME)

re :	 fclean all
