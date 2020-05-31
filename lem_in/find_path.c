#include "lem_in.h"

void 		set_visitzero(t_farm **a, t_farm *head)
{
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->room_id == -2)
			(*a)->visit = 0;
		(*a) = (*a)->next;
	}
}

int 		num_of_links(t_farm **a, t_farm *head, t_farm *node)
{
	int 	ret;
	int 	i;
	t_farm 	*temp;

	i = 0;
	ret = 0;
	temp = NULL;
	temp = (*a);
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->links != NULL && (*a)->links[0] != (*a))
		{
			while ((*a)->links[i] != (*a))
			{
				if ((*a)->links[i] == node)
					ret++;
				else if (((*a) == node) && ((*a)->links[i] != (*a)))
					ret++;
				i++;
			}
			i = 0;
		}
		(*a) = (*a)->next;
	}
	(*a) = temp;
	return (ret);
}

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
	t_farm 	*base;

	i = 0;
	j = NULL;
	base = NULL;
	(*a) = head->next;
	while ((*a)->room_id != 1)
		(*a) = (*a)->next;
	base = (*a);
	
	return (0);
}

int 		find_path(t_farm **a, t_farm *head)
{
	int 	i;
	int 	end_links;
	t_farm	*path;

	i = 0;
	path = NULL;
/*	end_links = num_of_endlinks(a, head);
	if (end_links == 0)
	{
		ft_putendl("No one is linked to end");
		return (0);
	}
*/
	(*a) = head->next;
	while ((*a) != NULL)
	{	
		(*a)->total_links = num_of_links(a, head, (*a));
		(*a) = (*a)->next;
	}
	ft_putendl("Out");
	(*a) = head->next;
	while ((*a) != NULL)
	{
		ft_putstr((*a)->room_name);
		ft_putstr(" ");
		ft_putnbr((*a)->total_links);
		ft_putchar('\n');
		(*a) = (*a)->next;
	}

	/*
	if (search_path(a, head, &path, end_links) == -1)
	{
		ft_putendl("Dead end");
		return (0);
	}
	*/
//	print_result(a, head, &path);
	return (1);
}