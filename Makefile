NAME= cub3D

MAIN= src/main.c

PARSER= parser.c

DISPLAY= display.c

INIT= mlx.c player.c

EVENT= handler.c

RAYCAST= utils.c raycast.c

OBJS_PARSER = $(addprefix src/parser/, $(PARSER:.c=.o))

OBJS_DISPLAY = $(addprefix src/display/, $(DISPLAY:.c=.o))

OBJS_INIT = $(addprefix src/init/, $(INIT:.c=.o))

OBJS_EVENT = $(addprefix src/event/, $(EVENT:.c=.o))

OBJS_RAYCAST = $(addprefix src/raycast/, $(RAYCAST:.c=.o))

OBJS= $(OBJS_PARSER) $(MAIN:.c=.o) $(OBJS_DISPLAY) $(OBJS_INIT) $(OBJS_EVENT) $(OBJS_RAYCAST)

CFLAGS= -Wall -Werror -Wextra -g3

CC=cc

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	 $(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I./include -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean:
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re