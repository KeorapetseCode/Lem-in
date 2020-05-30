#include "lem_in.h"

int 		check_links(t_farm **a, t_farm *head)
{
	int 	s_num;
	int 	e_num;
	int 	i;
	t_farm 	*start_node;
	t_farm 	*end_node;

	i = 0;
	s_num = 0;
	e_num = 0;
	start_node = NULL;
	end_node = NULL;
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->room_id == 1)
		{
			start_node = (*a);
			s_num++;
		}
		else if ((*a)->room_id == 2)
		{
			end_node = (*a);
			e_num++;
		}
		else if (start_node != NULL && end_node != NULL)
			break ;
		(*a) = (*a)->next;
	}
	if (start_node == NULL || end_node == NULL || (start_node == end_node))
	{
		ft_putendl("No start or end node");
		return (-1);
	}
	if (s_num > 1 || e_num > 1)
	{
		ft_putendl("Multiple Start or End Room");
		return (-1);
	}
	s_num = 0;
	e_num = 0;
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->links != NULL && (*a)->links[0] != (*a))
		{
			while ((*a)->links[i] != (*a))
			{
				if ((*a)->links[i] == start_node)
				{
					if (s_num == 0)
						s_num = 1;
				}
				else if ((*a)->links[i] == end_node)
				{
					if (e_num == 0)
						e_num = 1;
				}
				else if (((*a) == end_node) && ((*a)->links[i] != (*a)))
				{
					if (e_num == 0)
						e_num = 1;
				}
				else if (((*a) == start_node) && ((*a)->links[i] != (*a)))
				{
					if (s_num == 0)
						s_num = 1;
				}
				i++;
			}
			i = 0;
		}
		(*a) = (*a)->next;
	}
	(*a) = head->next;
	return (s_num + e_num);
}

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
}