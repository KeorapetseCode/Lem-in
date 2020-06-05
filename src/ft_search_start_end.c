#include "lem_in.h"
//This function is called by ft_create_rooms.
//The rest is self explanitory.
//It also re checked by lem-in.c 
int     	ft_search_start_end(char *line)
{
	if (ft_strequ(line, "##start"))
		return 1;
	else if (ft_strequ(line, "##end"))
		return 2;
	return 0;
}

int 		ft_search_mult_startend(char **line)
{
	int 	start;
	int 	end;
	int 	i;

	i = 0;
	start = 0;
	end = 0;
	while (line[i] != NULL)
	{
		if (ft_strnstr(line[i], "##start", 7))
			start++;
		else if (ft_strnstr(line[i], "##end", 5))
			end++;
		i++;
	}
	if ((start + end) == 2)
		return (2);
	return (0);
}