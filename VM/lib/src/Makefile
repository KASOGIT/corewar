##
## Makefile for MakeFile in /home/soto_a/rendu/Piscine_C_J11/lib/my
## 
## Made by Kaso Soto
## Login   <soto_a@epitech.net>
## 
## Started on  Mon Oct 20 10:48:31 2014 Kaso Soto
## Last update Sat Dec  6 13:07:26 2014 Kaso Soto
##

SRC=	my_str_isprintable.c \
	my_showstr.c \
        my_str_isupper.c \
	my_find_prime_sup.c \
	my_show_wordtab.c \
	my_strlcat.c \
	my_getnbr_base.c \
	my_sort_int_tab.c \
	my_strlen.c \
	my_getnbr.c \
	my_square_root.c \
	my_strlowcase.c \
	my_isneg.c \
        my_strcapitalize.c \
	my_strncat.c \
	my_is_prime.c \
        my_strcat.c \
        my_strncmp.c \
	my_power_rec.c \
        my_strcmp.c \
        my_strncpy.c \
	my_putchar.c \
        my_strcpy.c \
        my_strstr.c \
	my_putnbr_base.c \
        my_strdup.c \
        my_str_to_wordtab.c \
	my_put_nbr.c \
        my_str_isalpha.c \
        my_strupcase.c \
	my_putstr.c \
        my_str_islower.c \
	my_strword.c \
	my_revstr.c \
        my_str_isnum.c \
	my_char_is_print.c

LIB	= libmy.a

NAME	= libmy

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -I./include/

all:	$(NAME)

$(NAME):$(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	cp $(LIB) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re:	fclean all
