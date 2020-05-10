#include "lem_in.h"

void 		room_incr(int *room, int *pos)
{//This function is to minimize the no. of lines in the num_of_rooms function
	(*room)++;
	(*pos)++;
}

int 		num_of_rooms(char **map_strngs)
{
	int 	i;
	int 	room;
	int 	start;
	int 	end;

	start = 0;//if it finds "start" again it will ignore that string 
	end = 0;//if it finds "end" again it will ignore that string.
	room = 0;
	i = 1;//Start from the 2nd string, because the first one is the no. of ants 
	if (map_strngs == NULL || map_strngs[0] == NULL)
		return (-1);
	while (map_strngs[i] != NULL)
	{
		if (ft_strnstr(map_strngs[i], "start", 5) && start == 0)
			room_incr(&room, &start);
		else if (ft_strnstr(map_strngs[i], "end", 3) && end == 0)
			room_incr(&room, &end);
		else if (ft_isdigit(map_strngs[i][0]) && map_strngs[i][1] != '-')
			room++;
		else if (ft_isdigit(map_strngs[i][0]) && map_strngs[i][1] == '\0')
			room++;
		i++;
	}
	return (room);
}