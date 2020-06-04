#include "lem_in.h"
//This function is called by ft_create_rooms.
//The rest is self explanitory. 
int     	ft_search_start_end(char *line)
{
	if (ft_strequ(line, "##start"))
		return 1;
	else if (ft_strequ(line, "##end"))
		return 2;
	return 0;
}