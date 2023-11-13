###############################################
CC := cc
CFLAGS := -Wall -Werror -Wextra
###############################################
NAME=so_long
SRC=	main.c	\
		map.c	\
		find_path.c \
		game.c \
		player.c \
		screen.c
OBJ=$(SRC:%.c=%.o)
###############################################
SRC_FOLDER=src

MLB_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
###############################################

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $^ $(MLB_FLAGS) -o $(NAME)

libft/libft.a:
	@make -C libft/

test: del.o
	cc del.o $(MLB_FLAGS) -o end

%.o: $(SRC_FOLDER)/%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

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