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

	if (!ft_is_room(roomName))
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
