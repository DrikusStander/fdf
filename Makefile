NAME = fdf

SRC = 	fdf.c	keyhook.c	xx_y1y2.c	xy1_xy2.c putline.c toiso.c readmap.c

LIBS = -lmlx -L./libft -lft 

FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit $(LIBS)

HEADERS = fdf.h

all : $(NAME)

$(NAME) : 
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
