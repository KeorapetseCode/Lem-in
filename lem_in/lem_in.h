#ifndef LEM_IN_H
# define LEM_IN_H

#include "get_next_line/get_next_line.h"

int 		num_of_rooms(char **map_strngs);
int 		num_of_ants(char **map_strngs);
char		**fd_strings(int fd);
void 		create_antfarm(char **map_strngs, int total_rooms, int total_ants);
void		null_var(t_farm *var);
void 		null_ptr(t_farm **ptr);

typedef struct  		ant_farm
{
	char 				*room_name;
	char 				**ant;
	struct ant_farm		**links;
	struct ant_farm 	*next;
}						t_farm;



#endif