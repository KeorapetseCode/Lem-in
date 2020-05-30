
NAME = lem_in.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = find_path.c print_input.c links.c alloc_ants.c make_list.c ant_farm.c num_of_rooms.c fd_strings.c lem_in.c get_next_line/get_next_line.c

OBJECTS = find_path.o print_input.o links.o alloc_ants.o make_list.o ant_farm.o num_of_rooms.o fd_strings.o lem_in.o get_next_line.o

all: $(NAME)

$(NAME):
#	make re -C get_next_line/libft
	$(CC) $(SOURCES) -c
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	$(CC) lem_in.c $(NAME) get_next_line/libft/libft.a -o lem_in
	make clean

clean:
#	make fclean -C get_next_line/libft
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all