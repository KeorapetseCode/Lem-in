#include "lem_in.h"

int 		num_of_endlinks(t_farm **a, t_farm *head)
{

	int 	e_num;
	int 	i;
	t_farm 	*end_node;

	i = 0;
	e_num = 0;
	end_node = NULL;
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->room_id == 2)
			end_node = (*a);
		else if (end_node != NULL)
			break ;
		(*a) = (*a)->next;
	}
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->links != NULL && (*a)->links[0] != (*a))
		{
			while ((*a)->links[i] != (*a))
			{
				if ((*a)->links[i] == end_node)
					e_num++;
				else if (((*a) == end_node) && ((*a)->links[i] != (*a)))
					e_num++;
				i++;
			}
			i = 0;
		}
		(*a) = (*a)->next;
	}
	(*a) = head->next;
	return (e_num);
}

int 		search_path(t_farm **a, t_farm *head, t_farm **path, int end_links)
{
	int 	i;
	t_farm	*j;

	i = 0;
	j = NULL;
	while ((*a) != NULL)
	{
		if ((*a)->room_id == 2)
			break ;
		(*a) = (*a)->next;
	}
	ft_putendl((*a)->room_name);
	j = (*a);
/*	while ((*a) != NULL)
	{

	}*/
//	return (0);
}

int 		find_path(t_farm **a, t_farm *head)
{
	int 	i;
	int 	end_links;
	t_farm	*path;

	i = 0;
	path = NULL;
	end_links = num_of_endlinks(a, head);
	if (end_links == 0)
	{
		ft_putendl("No one is linked to end");
		return (0);
	}
	if (search_path(a, head, &path, end_links) == -1)
	{
		ft_putendl("Dead end");
		return (0);
	}
//	print_result(a, head, &path);
	return (1);
}