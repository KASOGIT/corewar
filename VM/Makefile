##
## Makefile for Makefile
##
## Made by kaso soto
## Login     <soto_a@epitech.net>
##
## Started on 2015
## Last update Sun Oct 16 16:07:11 2016 
##

NAME	= VM/corewar

CC	= gcc

SRC	= VM/vm.c \
	  tab_op/op.c \
          linked_list/delete_func_on_list.c \
          linked_list/display_on_list.c \
          linked_list/usual_func_on_list.c \
	  linked_list/parsing_champ_check_set.c \
	  linked_list/parsing_champ_load_champ.c \
	  linked_list/parsing_champ_misc.c \
	  linked_list/parsing_champ_load_champ_memory.c \
	  endian/convert_endian.c \
	  GAME/game.c \
	  GAME/game_misc.c \
	  GAME/tab_ptr_func.c \
	  GAME/dump_memory.c \
	  manage_error/put_error.c \
	  convert_data/convert_string_to_int.c \
	  convert_data/convert_string_to_short.c \
	  convert_data/get_byte_code.c \
	  convert_data/convert_int_to_string.c \
	  convert_data/convert_short_to_string.c \
	  act_for_instr/act_on_reg.c \
	  act_for_instr/act_on_var_champ.c \
	  act_for_instr/get_pos.c \
	  act_for_instr/act_on_memory.c \
	  act_for_instr/get_values.c \
	  act_for_instr/get_values_spec.c \
	  instructions/my_live.c \
	  instructions/my_ld.c \
	  instructions/my_st.c \
	  instructions/my_add.c \
	  instructions/my_sub.c \
	  instructions/my_and.c \
	  instructions/my_or.c \
	  instructions/my_xor.c \
	  instructions/my_zjmp.c \
	  instructions/my_ldi.c \
	  instructions/my_sti.c \
	  instructions/my_fork.c \
	  instructions/my_lld.c \
	  instructions/my_lldi.c \
	  instructions/my_lfork.c \
	  instructions/my_aff.c \

OBJ	= $(SRC:.c=.o)

CFLAGS	= -I./include/ -pipe #-W -Wall -Wextra -g3

LFLAGS  = -L./lib/ -lmy

$(NAME): $(OBJ)
	 $(MAKE) -C lib/src
	 $(CC) $(OBJ) $(LFLAGS) -o $(NAME)

all :	 $(NAME)

clean :
	 $(MAKE) -C lib/src clean
	 rm -f $(OBJ)

fclean : clean
	 $(MAKE) -C lib/src fclean
	 rm -f $(NAME)

re: fclean all
