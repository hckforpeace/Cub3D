NAME= cub3D

MAIN= src/main.c

PARSER= parser.c

DISPLAY= display.c

OBJS_PARSER = $(addprefix src/parser/, $(PARSER:.c=.o))

OBJS_DISPLAY = $(addprefix src/display/, $(DISPLAY:.c=.o))

OBJS= $(OBJS_PARSER) $(MAIN:.c=.o) $(OBJS_DISPLAY)

CFLAGS= -Wall -Werror -Wextra

CC=cc

all: $(NAME)

$(NAME): $(OBJS) 
	@make -C libft
	@$(CC) $(CFLAGS) $^  -lft -L./libft -o $@
#   -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -I./include -c $< -o $@

clean:
	@rm -f $(OBJS)
# $(info()) 
fclean:
	make fclean -C libft
	rm -f $(NAME)
re: fclean re
