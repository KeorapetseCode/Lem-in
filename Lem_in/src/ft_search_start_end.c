#include "lem_in.h"

int     	ft_search_start_end(char *line)
{
	if (ft_strnequ(line, "##start", 7))
		return (1);
	else if (ft_strnequ(line, "##end", 5))
		return (2);
	return (0);
}