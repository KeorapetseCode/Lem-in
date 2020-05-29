#include "lem_in.h"

int 	total_ants(char **map_strngs)
{
	if (map_strngs != NULL && map_strngs[0] != NULL)
		return (ft_atoi(map_strngs[0]));
	else
		return (-1);
	return (0);
}

int 		main()
{
	char 	**map_strngs;
	t_farm 	*a;
	t_farm	head;

	a = NULL;
	head.next = NULL;
	map_strngs = fd_strings(0);
	if (map_valid(map_strngs) == -1)
	{
		ft_putendl("Error With Input File!!!");
		exit(0);
	}
	make_list(&a, &head, map_strngs, total_rooms(map_strngs));
	ants_alloc(&a, &head, map_strngs);
	links_alloc(&a, &head, map_strngs);
	a = head.next;
	
	
/*	int x = 0;
	while (a != NULL)
	{
		if (a->links == NULL)
		{
			ft_putstr(a->room_name);
			ft_putendl(" has NULL links");
		}
		else
			printf("%s\n", a->room_name);
		x++;
		a = a->next;
	}
*/
//	create_antfarm(fd_data, num_of_rooms(fd_data), num_of_ants(fd_data));	
	
	return (0);
}