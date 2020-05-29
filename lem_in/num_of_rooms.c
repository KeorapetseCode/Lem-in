#include "lem_in.h"

int 		total_rooms(char **map_strngs)
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
		{
			room++;
			start++;
		}
		else if (ft_strnstr(map_strngs[i], "end", 3) && end == 0)
		{
			room++;
			end++;
		}
		else if ((!(ft_strchr(map_strngs[i], '-'))) && map_strngs[i][0] != '#')
			room++;
		i++;
	}
	return (room);
}