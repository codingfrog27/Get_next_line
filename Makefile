$(NAME): a.out

$(NAME):
	gcc get_next_line.c get_next_line_utils.c main.c

debug:
	gcc get_next_line.c get_next_line_utils.c main.c

test: $(NAME)
	./a.out

leaks:
	gcc -fsanitize=address -g get_next_line.c get_next_line_utils.c main.c