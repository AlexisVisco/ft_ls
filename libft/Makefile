# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/17 14:07:28 by aviscogl     #+#   ##    ##    #+#        #
#    Updated: 2017/11/29 09:40:10 by aviscogl    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

C_FILES += \
\
io/ft_putchar.c \
io/ft_putchar_fd.c \
io/ft_putendl.c \
io/ft_putendl_fd.c \
io/ft_putnbr.c \
io/ft_putnbr_fd.c \
io/ft_putnbrbase.c \
io/ft_putstr.c \
io/ft_putstr_classic.c \
io/ft_putstr_fd.c \
io/ft_putdouble_fd.c \
io/ft_putdouble.c \
io/ft_putubase.c \
io/ft_putubase_fd.c \
\
is/ft_isalnum.c \
is/ft_isalpha.c \
is/ft_isascii.c \
is/ft_isdigit.c \
is/ft_isprint.c \
\
lib/ft_atoi.c \
lib/ft_itoa.c \
lib/ft_itoa_base.c \
\
lst/lst_add.c \
lst/lst_get.c \
lst/lst_foreach.c \
lst/lst_foreach_i.c \
lst/lst_map.c \
lst/lst_collect_if.c \
lst/lst_new.c \
lst/lst_print.c \
lst/lst_push.c \
lst/lst_remove_if.c \
lst/lst_clear.c \
lst/lst_shift.c \
lst/lst_pop.c \
lst/lst_find.c \
lst/lst_reverse.c \
lst/lst_swap.c \
lst/lst_sort.c \
lst/lst_remove_at.c \
lst/lst_size.c \
\
math/math_abs.c \
math/math_intlen.c \
math/math_pgcd.c \
math/math_pow.c \
math/math_round.c \
math/math_sqrt.c \
\
mem/ft_bzero.c \
mem/free_debug.c \
mem/free_smart.c \
mem/ft_memalloc.c \
mem/ft_memccpy.c \
mem/ft_memchr.c \
mem/ft_memcmp.c \
mem/ft_memcpy.c \
mem/ft_memdel.c \
mem/ft_memmove.c \
mem/ft_memset.c \
\
printf/ft_printf.c \
printf/print_binary.c \
printf/print_char.c \
printf/print_hex.c \
printf/print_nb.c \
printf/print_str.c \
printf/print_str_pad.c \
printf/print_int_pad.c \
\
str/ft_strcat.c \
str/ft_strchr.c \
str/ft_strclr.c \
str/ft_strcmp.c \
str/ft_strmatch.c \
str/ft_strjoin_multiple.c \
str/ft_strisdigit.c \
str/ft_strcpy.c \
str/ft_strdel.c \
str/ft_strdup.c \
str/ft_strequ.c \
str/ft_striter.c \
str/ft_striteri.c \
str/ft_strjoin.c \
str/ft_strjoinch.c \
str/ft_strlcat.c \
str/ft_strlen.c \
str/ft_strlen_classic.c \
str/ft_strmap.c \
str/ft_strmapi.c \
str/ft_strncat.c \
str/ft_strncmp.c \
str/ft_strncpy.c \
str/ft_strnequ.c \
str/ft_strnew.c \
str/ft_strnstr.c \
str/ft_strrchr.c \
str/ft_strreplace.c \
str/ft_strreplace_first.c \
str/ft_strsplit.c \
str/ft_strstr.c \
str/ft_strsub.c \
str/ft_strtrim.c \
str/ft_tolower.c \
str/ft_toupper.c \

PROJECT = libft
NAME = $(PROJECT).a
CC = gcc
CFLAGS += -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_PATHS = io is lib lst math mem printf str

OBJ_SUB_PATHS = $(addprefix $(OBJ_PATH),$(OBJ_PATHS))
OBJ_NAME = $(C_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(C_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_SUB_PATHS)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	ar -rc $(NAME) $?
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

test: all
	gcc -L. -lft -I $(INC_PATH) main/main.c -o test_libft.out

##	Use the compiled libft : 
##		gcc -L. -lft -I $(INC_PATH) [C_FILES] -o [NAME_OUTPUT]

.PHONY: clean fclean re