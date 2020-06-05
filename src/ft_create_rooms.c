#include "lem_in.h"

//This function will only be called when GNL is reading a string that does not start with '#'
//Will also initialize t_keys->start and end strings using (int check_start_end) values
//NB (Remember this function is called inside a loop).

void    	ft_room(char *line, t_keys *keys, int check_start_end)
{
	int		i;
	char	**name;

	if (!ft_strchr(line, ' ') || ft_strchr(line, '#') || line[0] == 'L')
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	name = ft_strsplit(line, ' ');
	i = 0;
	while (name[i])
		i++;
	if (i != 3) //There neeeds to be 3 strings.
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (check_start_end == 1)
		keys->start = ft_strdup(name[0]);
	if (check_start_end == 2)
		keys->end = ft_strdup(name[0]);
	i = 0;
	while (name[i])
	{
		free(name[i]);
		i++;
	}
	free(name);
}
//(Be carefull)There's ft_room and ft_rooms.
//
t_rooms    *ft_create_rooms(t_keys *keys, t_rooms *rooms)
{
	char	**line;
	char	*temp;
	int		check_start_end;
	int 	i;

	i = 0;
	line = read_for_rooms(keys);
	if (ft_search_mult_startend(line) != 2)
	{
		ft_putendl("Error");
		exit(0);
	}
	ft_putnbr(keys->ants);
	ft_putchar('\n');
	i = 0;
	check_start_end = 0;
	while (line[i] != NULL)
	{
		temp = ft_strdup(line[i]);
		if (check_start_end == 1)
			ft_room(temp, keys, check_start_end);
		else if (check_start_end == 2)
			ft_room(temp, keys, check_start_end);
		check_start_end = ft_search_start_end(line[i]);
		if (line[i][0] != '#' && ft_strchr(line[i], ' '))
			rooms = ft_rooms(rooms, line[i], keys);
		ft_putendl(line[i]); //This line prints out the rooms and not the links
		free(temp);
		i++;
	}
	free(line);

//	ft_putchar('\n');
	return (rooms);
}