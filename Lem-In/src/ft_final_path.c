#include "lem_in.h"

int			ft_is_path(char *str, t_path *path)
{
	t_path	*temp;

	temp = path;
	while(temp)
	{
		if (!ft_strcmp(str, path->map))
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_path		*ft_add_to_path(t_path *path, t_rooms *rooms, t_keys *keys)
{
	t_path	*node;
	t_path	*temp;

	if (ft_is_path(rooms->data, path))
		return (path);
	if (!(node = (t_path *)malloc(sizeof(t_path *))))
	{
        ft_putstr("ERROR\n");
        exit(0);
    }
	node->map = ft_strdup(rooms->data);
	node->next = NULL;
	if (!path)
		path = node;
	else
	{
		temp = path;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	keys->room_counter++;
	return (path);
}


t_path		*ft_final_path(t_path *visit, t_path *path, t_rooms *rooms, t_keys *keys)
{
	int		i;
	int		j;
	t_rooms	*temp;

	i = 0;
	while (i < keys->rooms && i > -1)
	{
		j = 0;
		temp = rooms;
		while (j < keys->rooms && temp)
		{
			if (j == visit->visits[i])
				path = ft_add_to_path(path, temp, keys);
			temp = temp->next;
			j++;
		}
		i++;
	}
	return (path);
}

t_path 		*check_path(t_keys *keys, t_path *path)
{
	t_path 	*temp;
	t_path 	*head;
	t_path 	*j;
	t_path 	*k;
	int 	i;
	int  	a;


	temp = path;
	head = temp;
	j = NULL;
	a = 0;
	i = 0;
	keys->room_counter = 0;
	while (temp != NULL)
	{
		keys->room_counter++;
		if (!ft_strcmp(temp->map, keys->end))
			break ;
		temp = temp->next;
	}
	j = temp;
	while (j != NULL)
	{
		j = j->next;
		i++;
	}
	j = temp;
	while (i != 0)
	{
		while (a < i)
		{
			k = j;
			j = j->next;
			a++;
		}
		free(j);
		k->next = NULL;
		i--;
		a = 0;
		j = temp;
	}
//	free(temp->next);
	temp->next = NULL;
	temp = head;
	return (temp);
}