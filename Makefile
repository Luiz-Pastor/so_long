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
		screen.c \
		movement.c \
		check_map.c \
		print_sprites.c \
		set_sprites.c \
		change_sprites.c
OBJ=$(SRC:%.c=%.o)
SRC_FOLDER=src
HEADER=structs.h game.h map.h movement.h player.h screen.h
###############################################
MLB_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
###############################################

all: $(NAME) run

$(NAME): $(OBJ) libft/libft.a
	$(CC) $^ $(MLB_FLAGS) -o $(NAME)

libft/libft.a:
	@make -C libft/

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
	@make $(NAME)

.PHONY: all clean fclean re nm norminette

###############################################

nm: norminette
norminette:
	@norminette src/ inc/ libft/ | grep -v "OK!"