#include "lem_in.h"
//This function is called by ft_create links.
//This is the function that is responsible for giving t_keys->rooms its value.
//
//
t_rooms		*ft_rooms(t_rooms *rooms, char *roomName, t_keys *keys)
{
	t_rooms	*node;
	t_rooms	*temp;
	int		i;

	if (!ft_is_room(roomName))//Checks if the room name is valid(int max and NULL terminator in the string)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (ft_check_room(roomName, rooms) || roomName[0] == 'L')
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	i = ft_strchr(roomName, ' ') - roomName;
	if (!(node = (t_rooms *)malloc(sizeof(t_rooms))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	node->data = ft_strndup(roomName, i);
	node->next = NULL;
	keys->rooms++;
	if (!rooms)
		rooms = node;
	else
	{
		temp = rooms;
		while(temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return (rooms);
}

char		**read_for_rooms(t_keys *keys)
{
	char 	*line;
	char 	*raw_str;
	char 	*temp;
	char 	**ret;

	raw_str = NULL;
	temp = NULL;
	ret = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strchr(line, ' ') && line[0] != '#')
		{
			keys->read = ft_strdup(line);
			break ;
		}
		raw_str = ft_strjoin(temp, line);
		temp = ft_strjoin(raw_str, "@");
	}
	if (ft_strlen(line) == 0)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	free(temp);
	free(line);
	ret = ft_strsplit(raw_str, '@');
	free(raw_str);
	return (ret);
}



