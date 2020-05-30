#include "lem_in.h"

void 		print_input(char **map_strngs)
{
	int 	i;

	i = 0;
	while (map_strngs[i] != NULL)
	{
		ft_putendl(map_strngs[i]);
		i++;
	}
	ft_putchar('\n');
	return ;
}