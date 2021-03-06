#include "lem_in.h"

void		empty_stack(char **tmp, int i)
{
	int	j;

	j = 0;
	while(tmp[j] && j < i)
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

void		empty_path(t_path *path)
{
	t_path	*current;

	current = NULL;
	while ((current = path) != NULL)
	{
		path = path->next;
		free(current->map);
		free(current);
	}
//	free(path);
}

void		empty_rooms(t_rooms *rooms)
{
	t_rooms	*current;

	current = NULL;
	while ((current = rooms) != NULL)
	{
		rooms = rooms->next;
		free(current->data);
		free(current);
	}
//	free(rooms);
}

void		empty_map(t_notes *map)
{
	t_notes	*current;

	current = NULL;
	while ((current = map) != NULL)
	{
		map = map->next;
		free(current->note);
		free(current);
	}
//	free(map);
}

void		empty_links(t_links *links, t_keys *keys)
{
	int	i;

	i = 0;
	while(i < keys->rooms)
	{
		free(links->links[i]);
		i++;
	}
	free(links->links);
	free(links);
}

void		empty(t_links *links, t_rooms *rooms, t_keys *keys, t_path *path, t_path *paths, t_notes *map)
{
	empty_links(links, keys);

	empty_path(path);
	free(paths->visits);	
	free(paths);

	empty_rooms(rooms);
	empty_map(map);

	free(keys->start);
	free(keys->end);
	free(keys->read);
}
