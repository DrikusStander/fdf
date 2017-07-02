NAME = fdf

SRC = fdf.c	keyhook.c xx_y1y2.c	xy1_xy2.c putline.c toiso.c readmap.c

LIBS = -lmlx -L./libft -lft 

FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit $(LIBS)

HEADERS = fdf.h

all : $(NAME)

$(NAME) :
	make -C ./libft/
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	make clean -C ./libft/

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
	make re -C ./libft/
