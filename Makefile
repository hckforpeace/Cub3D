NAME= cub3D

MAIN= src/main.c

PARSER= parser.c parser_header.c parser_map.c parser_save.c parser_exit.c parser_init.c

SPRITE= sprite.c

ANIMATION= init_animation.c

UTILS= utils_parse.c utils_lst.c utils_save_map.c utils_sprite.c

DISPLAY= display.c

OBJS_ANIMATION = $(addprefix src/animation/, $(ANIMATION:.c=.o))
OBJS_SPRITE = $(addprefix src/sprite/, $(SPRITE:.c=.o))
OBJS_PARSER = $(addprefix src/parser/, $(PARSER:.c=.o))
OBJS_DISPLAY = $(addprefix src/display/, $(DISPLAY:.c=.o))
OBJS_UTILS = $(addprefix src/utils/, $(UTILS:.c=.o))


OBJS= $(OBJS_ANIMATION) $(OBJS_SPRITE) $(OBJS_PARSER) $(MAIN:.c=.o) $(OBJS_DISPLAY) $(OBJS_UTILS)

# CFLAGS= -Wall -Werror -Wextra

CC=cc

all: $(NAME)

$(NAME): $(OBJS) 
	@make -C libft
	@$(CC) $(CFLAGS) $^  -lft -L./libft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

%.o : %.c
	@$(CC) $(CFLAGS) -I./include -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
