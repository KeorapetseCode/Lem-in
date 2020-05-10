#include "lem_in.h"

int 	num_of_ants(char **map_strngs)
{
	if (map_strngs != NULL && map_strngs[0] != NULL)
		return (ft_atoi(map_strngs[0]));
	else
		return (-1);
	return (0);
}

int 	main()
{
	char 	**fd_data;
	int 	a;

	a = 0;
	fd_data = fd_strings(0);

	//	create_antfarm(fd_data, num_of_rooms(fd_data), num_of_ants(fd_data));
/*
	while (fd_data[a] != NULL)
	{
		ft_putendl(fd_data[a]);
		a++;
	}
*/
	return (0);
}