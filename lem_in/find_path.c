#include "lem_in.h"

void 		set_zero(t_farm **a, t_farm *head)
{
	(*a) = head->next;
	while ((*a) != NULL)
	{
		(*a)->visit = 0;
		(*a)->prev = NULL;
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

t_farm 		*search_path(t_farm *b, t_farm *a)
{
	int 	i;
	while (b != NULL)
	{
		
		b = b->next;
	}
}
int 		search_path(t_farm **a, t_farm *head, t_farm **path, int end_links)
{
	int 	i;
	t_farm	*temp;
	t_farm 	*b;

	i = 0;
	temp = NULL;
	b = NULL;
	(*a) = head->next;
	while ((*a)->room_id != 2) //Setting a to end node
		(*a) = (*a)->next;
	b = head->next;
	while ((*a)->room_id != 1)
	{
		if ((*a)->visit < (*a)->total_links)
		{
			(*a)->prev = temp;
			temp = (*a);
			(*a)->visit += 1;
			if ((*a) == (*a)->links[(*a)->visit-1])
			{
				(*a) = search_connect(b, (*a))
				b = head->next;
				if ((*a) == NULL)
					ft_putendl("No More links");
			}
			else
				(*a) = (*a)->links[(*a)->visit-1];
		}
		else
		{
			(*a) = (*a)->prev;
			if ((*a) == NULL)
			{
				ft_putendl("Dead");
				exit(0);
			}
		}
	}
	return (0);
}

int 		find_path(t_farm **a, t_farm *head)
{
	int 	i;
	int 	end_links;
	t_farm	*path;

	i = 0;
	path = NULL;
	(*a) = head->next;
	while ((*a) != NULL)
	{	
		(*a)->total_links = num_of_links(a, head, (*a));
		(*a) = (*a)->next;
	}
	(*a) = head->next;
	set_zero(a, head);
	(*a) = head->next;
	if (search_path(a, head, &path, end_links) == -1)
	{
		ft_putendl("Dead end");
		return (0);
	}
//	print_result(a, head, &path);
	return (1);
}