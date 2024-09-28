NAME= cub3D

all: $(NAME)

NAME:
	# -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c


clean:

fclean:

re: fclean re

