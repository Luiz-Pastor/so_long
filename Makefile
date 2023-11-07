###############################################
CC := cc
CFLAGS := -Wall -Werror -Wextra
###############################################
NAME=so_long
SRC=	main.c	\
		map.c	\
		find_path.c \
		game.c \
		player.c
OBJ=$(SRC:%.c=%.o)
###############################################
SRC_FOLDER=src
###############################################

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $^ -o $(NAME) -Llibft/ -lft

libft/libft.a:
	@make -C libft/

%.o: $(SRC_FOLDER)/%.c
	$(CC) $(CFLAGS) -c $<

###############################################

run: $(NAME)
	./so_long maps/map.ber


###############################################

clean:
	@rm -rf $(OBJ)
	@make -C libft/ libft_clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ libft_fclean

re: fclean
	@make -C libft/ libft_re
	make $(NAME)

.PHONY: all clean fclean re