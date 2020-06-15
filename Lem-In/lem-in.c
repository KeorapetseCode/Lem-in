#include "src/lem_in.h"

int         main()
{
	t_keys 	keys;
	t_rooms	*rooms;
	t_notes	*map;
	t_links	*links;
	t_path	*paths;
	t_path	*path;
	
	rooms = NULL;
	map = NULL;
	path = NULL;
	links = NULL;
	paths = NULL;
	
	ft_begin(&keys);
	map = ft_create_map(map);
	if (map != NULL && ft_rooms_map(map) > 1 && ft_link_map(map) > 0 && ft_dest_present(map) == 2)
	{
		ft_num_of_ants(&keys, map);
		rooms = ft_create_rooms(&keys, rooms, map);
		links = ft_create_links(links, rooms, &keys, map);
		
		ft_check_start_end(&keys);
		paths = ft_create_path(rooms, links, &keys, paths);
    	if (paths == NULL)
    	{
    		empty_links(links, &keys);
    	 	free(keys.start);
			free(keys.end);
			free(keys.read);
			empty_rooms(rooms);
			empty_map(map);
    		ft_putendl("ERROR");
    		exit(0);
    	}
    	path = ft_final_path(paths, path, rooms, &keys);
		ft_display_map(map);
		path = check_path(&keys, path);
		path = ft_display_1(path, &keys);
		empty(links, rooms, &keys, path, paths, map);
	}
	else 
	{
		empty_map(map);
		ft_putendl("ERROR");
		exit(0);
	}
	return (0);
}