#include "lem_in.h"
//links len is the inportant variable in this function.
//It gets its value from the file ft_rooms.c
//what links_len has is the number of rooms which are pointing to other rooms.
//This is essential because when allocating memory. (NB) t_links is a 2d array.
//
t_links		*ft_make_links(t_links *links, int links_len)
{
	int	i;

	i = 0;
	if (!(links = (t_links *)malloc(sizeof(t_links))))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	if (!(links->links = (int **)malloc(sizeof(int*) * links_len)))
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	while (i < links_len)
	{
		if (!(links->links[i] = (int *)malloc(sizeof(int) * links_len)))
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
		i++;
	}
	return (links);
}
//Checks if the variable roomName is equals to what t_rooms->data is
int			ft_is_link(char *roomName, t_rooms *rooms)
{
	int		i;
	t_rooms	*temp;

	i = 0;
	temp = rooms;
	while (temp)
	{
		if (ft_strequ(roomName, temp->data))
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}