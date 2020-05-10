

NAME = lem_in.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ant_farm.c num_of_rooms.c fd_strings.c lem_in.c get_next_line/get_next_line.c

OBJECTS = ant_farm.o num_of_rooms.o fd_strings.o lem_in.o get_next_line.o

all: $(NAME)

$(NAME):
#	make libft
	$(CC) $(SOURCES) -c
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	$(CC) lem_in.c $(NAME) get_next_line/libft/libft.a -o lem_in

clean:
	/bin/rm -f get_next_line/libft/*.o
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all