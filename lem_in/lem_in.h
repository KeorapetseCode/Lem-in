#ifndef LEM_IN_H
# define LEM_IN_H

#include "get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct  		s_farm
{
	int 				room_id;
	char 				*room_name;
	char 				**ant;
	struct s_farm		**links;
	struct s_farm		*next;
}						t_farm;

int 					total_rooms(char **map_strngs);
int 					total_ants(char **map_strngs);
char					**fd_strings(int fd);
int 					map_valid(char **map_strngs);


void 					create_antfarm(char **map_strngs, int total_rooms, int total_ants);
void					create_links(t_farm **a, t_farm *head, char **map_strngs);
char					*room_writer(const char *s, char c);
int						compare(const char *s1, const char *s2);
char					*make_node_2(const char *s, char c);


void					make_list(t_farm **a, t_farm *head, char **map_strngs, int total_rooms);
void					ants_alloc(t_farm **a, t_farm *head, char **map_strngs);
void 					links_alloc(t_farm **a, t_farm *head, char **map_strngs);

#endif