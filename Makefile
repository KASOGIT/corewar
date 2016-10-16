##
## Makefile for corewar in /home/trambe_m/CPE_2014_corewar
## 
## Made by Manuel Trambert
## Login   <trambe_m@epitech.net>
## 
## Started on  Sun Apr 12 22:10:46 2015 Marcotte-Ruffin Félix
## Last update Sun Apr 12 23:41:04 2015 Felix Marcotte
##

CFLAGS	=	-I./ASM/include/ -W -Wall -Wextra -Werror

SRCS1	=	ASM/src/main.c \
		ASM/GNL/get_next_line.c \
		ASM/src/check_type.c \
		ASM/src/endian.c \
		ASM/src/utils.c \
		ASM/src/func_ptr.c \
		ASM/src/check.c \
		ASM/src/check_parameter.c \
		ASM/src/check_arg.c \
		ASM/src/header.c \
		ASM/src/error.c \
		ASM/src/label.c \
		ASM/src/parsing.c \
		ASM/src/list.c \
		ASM/src/op.c \
		ASM/src/my_strncmp.c \
		ASM/src/my_strncpy.c \
		ASM/src/free.c \
		ASM/src/my_str_to_wordtab.c \
		ASM/src/my_get_nbr.c \
		ASM/src/epur.c \
		ASM/src/parameter.c \
		ASM/src/size_parameter.c \
		ASM/src/is.c \
		ASM/src/fill_list.c \
		ASM/src/tools.c \
		ASM/src/size.c \
		ASM/src/init.c \
		ASM/src/write_prog.c \
		ASM/src/write_cmd.c \
		ASM/src/write_sti.c \
		ASM/src/write_sub.c \
		ASM/src/write_st.c \
		ASM/src/write_ld.c \
		ASM/src/write_and.c \
		ASM/src/write_or.c \
		ASM/src/write_xor.c \
		ASM/src/write_ldi.c \
		ASM/src/write_lld.c \
		ASM/src/write_lldi.c \
		ASM/src/write_lfork.c \
		ASM/src/write_aff.c \

OBJS1	=	$(SRCS1:.c=.o)

CFLAGS	=	-I./VM/include/ -W -Wall -Wextra -Werror

SRCS2	=	VM/VM/vm.c \
		VM/tab_op/op.c \
		VM/linked_list/delete_func_on_list.c \
		VM/linked_list/display_on_list.c \
		VM/linked_list/usual_func_on_list.c \
		VM/linked_list/parsing_champ_check_set.c \
		VM/linked_list/parsing_champ_load_champ.c \
		VM/linked_list/parsing_champ_misc.c \
		VM/linked_list/parsing_champ_load_champ_memory.c \
		VM/endian/convert_endian.c \
		VM/GAME/game.c \
		VM/GAME/game_misc.c \
		VM/GAME/tab_ptr_func.c \
		VM/GAME/dump_memory.c \
		VM/manage_error/put_error.c \
		VM/convert_data/convert_string_to_int.c \
		VM/convert_data/convert_string_to_short.c \
	 	VM/convert_data/get_byte_code.c \
	 	VM/convert_data/convert_int_to_string.c \
		VM/convert_data/convert_short_to_string.c \
		VM/act_for_instr/act_on_reg.c \
		VM/act_for_instr/act_on_var_champ.c \
		VM/act_for_instr/get_pos.c \
		VM/act_for_instr/act_on_memory.c \
		VM/act_for_instr/get_values.c \
		VM/act_for_instr/get_values_spec.c \
		VM/instructions/my_live.c \
		VM/instructions/my_ld.c \
		VM/instructions/my_st.c \
		VM/instructions/my_add.c \
		VM/instructions/my_sub.c \
		VM/instructions/my_and.c \
		VM/instructions/my_or.c \
		VM/instructions/my_xor.c \
		VM/instructions/my_zjmp.c \
		VM/instructions/my_ldi.c \
		VM/instructions/my_sti.c \
		VM/instructions/my_fork.c \
		VM/instructions/my_lld.c \
		VM/instructions/my_lldi.c \
		VM/instructions/my_lfork.c \
		VM/instructions/my_aff.c \

OBJS2	=	$(SRCS2:.c=.o)

NAME1	=	asm

NAME2	=	corewar

CFLAGS	+=	-I./ASM/include/ -W -Wall -Wextra -Werror

CFLAGS2	=	-I./VM/include/ -W -Wall -Wextra -Werror

LFLAGS2	=	-L./asm/lib/ -lmy -lSDL2 -lSDL2_ttf

CC	=	gcc

RM	=	rm -f

all:		$(NAME1) $(NAME2)

$(NAME1):
		cd ASM && make
		mv ASM/asm .
$(NAME2):
		cd VM && make
		mv VM/VM/corewar .
clean:
		cd ASM && make clean
		cd VM && make clean
		rm asm
		rm corewar

fclean:		
		cd ASM && make fclean
		rm asm
		cd VM && make fclean
		rm corewar

re:		fclean all

