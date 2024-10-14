NAME= cub3D

MAIN= src/main.c

PARSER= parser.c parser_header.c parser_map.c parser_save.c parser_exit.c parser_init.c

UTILS= utils_parse.c utils_lst.c utils_save_map.c 

DISPLAY= display.c

INIT= mlx.c player.c

EVENT= handler.c moves.c

RAYCAST= utils.c raycast.c

DRAW= draw.c color.c minimap.c

TEXTURES= textures.c

OBJS_PARSER = $(addprefix src/parser/, $(PARSER:.c=.o))
OBJS_DISPLAY = $(addprefix src/display/, $(DISPLAY:.c=.o))
OBJS_UTILS = $(addprefix src/utils/, $(UTILS:.c=.o))

OBJS_INIT = $(addprefix src/init/, $(INIT:.c=.o))

OBJS_EVENT = $(addprefix src/event/, $(EVENT:.c=.o))

OBJS_RAYCAST = $(addprefix src/raycast/, $(RAYCAST:.c=.o))

OBJS_DRAW = $(addprefix src/draw/, $(DRAW:.c=.o))

OBJS_TEXTURES = $(addprefix src/textures/, $(TEXTURES:.c=.o))

OBJS= $(OBJS_PARSER) $(MAIN:.c=.o) $(OBJS_DISPLAY) $(OBJS_UTILS) $(OBJS_INIT) $(OBJS_EVENT) $(OBJS_RAYCAST) $(OBJS_DRAW) $(OBJS_TEXTURES)

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
