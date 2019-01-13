SRC = fillit.c convert_tetr.c valid_check.c tetr_funcs.c solver.c create_map.c calc_wh.c solve_helpers.c
HEAD = fillit.h
NAME = fillit

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -L libft -lft -o fillit
clean:
fclean: clean
	rm -rf $(NAME)
re: fclean all
