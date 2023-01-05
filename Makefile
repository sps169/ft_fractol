NAME = fractol

SRC_DIR = ./src/
LIBFT_LIB = ./libft/libft.a

SRC = 	$(SRC_DIR)main.c			\
		$(SRC_DIR)fractal_maths.c	\
		$(SRC_DIR)coloring.c		\
		$(SRC_DIR)painter.c			\
		$(SRC_DIR)input_hooks.c		\
		$(SRC_DIR)navigation.c		\


OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

CFLAGS = -Wextra -Wall -Werror

CSANITIZE = -fsanitize=address -g3

INCLUDE = -Iinclude

CC = gcc

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -L./libft/ -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)


$(LIBFT_LIB):
	make -C libft

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

rerun: fclean run

.PHONY: all clean fclean re run rerun
