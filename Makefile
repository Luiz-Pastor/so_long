###############################################
CC := cc
CFLAGS := -Wall -Werror -Wextra
###############################################
NAME=so_long
SRC=main.c
OBJ=$(SRC:%.c=%.o)
###############################################
SRC_FOLDER=src
###############################################

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $^ -o $(NAME) -Llibft/ -lft

libft/libft.a:
	@make -sC libft/

%.o: $(SRC_FOLDER)/%.c
	$(CC) $(CFLAGS) -c $<

###############################################

clean:
	@rm -rf $(OBJ)
	@make -sC libft/ libft_clean

fclean: clean
	@rm -rf $(NAME)
	@make -sC libft/ libft_fclean

re: fclean
	@make -sC libft/ libft_re
	make $(NAME)

.PHONY: all clean fclean re