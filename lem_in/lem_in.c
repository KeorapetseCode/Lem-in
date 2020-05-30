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
	print_input(map_strngs);
	if (map_valid(map_strngs) == -1)
	{
		ft_putendl("Error With Input File!!!");
		exit(0);
	}
	make_list(&a, &head, map_strngs, total_rooms(map_strngs));
	ants_alloc(&a, &head, map_strngs);
	links_alloc(&a, &head, map_strngs);
	create_farm(&a, &head, map_strngs);
//	test_links(&a, &head);
	a = head.next;
	if (check_links(&a, &head) != 2)
	{
		ft_putendl("Your Links are not valid");
		exit(0);
	}
	if (find_path(&a, &head) == 0)
	{
		ft_putendl("There's no path to destination");
		exit(0);
	}
	ft_putchar('\n');
	return (0);
}