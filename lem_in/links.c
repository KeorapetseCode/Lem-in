#include "lem_in.h"

void 	alloc_totalinks(t_farm **a, t_farm *head, char **map_strngs, int total)
{
	while ((*a) != NULL)
	{
		if (!((*a)->links = (t_farm **)malloc((sizeof(t_farm *) * total) + sizeof(t_farm *))))
		{
			ft_putendl("Cannot Malloc Total links");
			exit(0);
		}
		(*a)->links[0] = (*a);
		(*a) = (*a)->next;
	}
	(*a) = head->next;
	while ((*a) != NULL)
	{
		(*a)->links[total] = NULL;
		(*a) = (*a)->next;	
	}
	(*a) = head->next;
	return ;
}

int		compare(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		else if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void 		link_nodes(t_farm **a, t_farm *temp)
{
	int 	i;
	
	i = 0;
	if (compare((*a)->links[0]->room_name, (*a)->room_name) == 0)
	{
		if (compare((*a)->room_name, temp->room_name) == 0)
			return ;
		(*a)->links[0] = temp;
		(*a)->links[1] = (*a);
		return ;
	}
	else
	{
		while (compare((*a)->room_name, (*a)->links[i]->room_name) > 0)
			i++;
		if (compare((*a)->links[i]->room_name, (*a)->room_name) == 0)
		{
			if (compare((*a)->room_name, temp->room_name) == 0)
				return ;
			(*a)->links[i] = temp;
			(*a)->links[i+1] = (*a);
			return ;
		}
	}
}

void 	create_links(t_farm **a, t_farm *head, char **map_strngs)
{
	int 	i;
	char 	*node_1;
	char 	*node_2;
	t_farm 	*temp;

	i = 1;
	node_1 = NULL;
	node_2 = NULL;
	temp = NULL;
	while (!(ft_strchr(map_strngs[i], '-')))
		i++;
	while (map_strngs[i] != NULL)
	{
		node_1 = room_writer(map_strngs[i], '-');
		node_2 = make_node_2(map_strngs[i], '-');
		(*a) = head->next;
		temp = head->next;
		while (temp != NULL)
		{
			if (compare(temp->room_name, node_2) == 0)
			{
				while ((*a) != NULL)
				{
					if (compare((*a)->room_name, node_1) == 0)
					{
						
						ft_putstr((*a)->room_name);
						ft_putstr("------");
						ft_putendl(temp->room_name);
						link_nodes(a, temp);
					}
					(*a) = (*a)->next;
				}
				if ((*a) == NULL)
					break ;
			}
			if (temp->next != NULL && (*a) != NULL)
				temp = temp->next;
		}
		i++;
	}
	if (map_strngs[i] == NULL)
	{
		ft_putstr("\n\nMap is done\n");
	//	exit(0);
		return ;
	}
}




void 	links_alloc(t_farm **a, t_farm *head, char **map_strngs)
{
	int 	total_links;

	total_links = map_valid(map_strngs);
	if (total_links < 1)
	{
		ft_putendl("Not enough links");
		exit(0);
	}
	(*a) = head->next;
	alloc_totalinks(a, head, map_strngs, total_links);
	create_links(a, head, map_strngs);
	int 	b = 0;
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->links == NULL)
		{
			ft_putstr((*a)->room_name);
			ft_putendl(" is NULL links");
		}
		else
		{
			while ((*a)->links[b] != NULL)
			{
				if (compare((*a)->links[b]->room_name, (*a)->room_name) > 0)
				{
					ft_putstr((*a)->room_name);
					ft_putstr(" -- ");
					ft_putendl((*a)->links[b]->room_name);	
				}
				b++;
			}
			b = 0;
			ft_putstr("\n");
		}
		(*a) = (*a)->next;
	}
}