NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

SRC_DIR = ./src/
SRC_NAME = lst_util.c push_swap.c push_func.c\
		swap_func.c rotate_func.c reverse_rotate_func.c\
		check_err_func.c push_swap_util.c sort_func.c\
		sort_small_stack_util.c sort_big_stack_util.c lst_util2.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(SRC:.c=.o)

INCLUDE = -I./include -I./libft
LINK = -L./libft -lft

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK) $(OBJ) -o $@

$(LIB):
	make -C $(LIB_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
