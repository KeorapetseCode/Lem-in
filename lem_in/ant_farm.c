#include "lem_in.h"

void 		null_ptr(t_farm **ptr)
{
	(*ptr)->room_name = NULL;
	(*ptr)->ant = NULL;
	(*ptr)->links = NULL;
	(*ptr)->next = NULL;
}

void		null_var(t_farm *var)
{
	var->room_name = NULL;
	var->ant = NULL;
	var->links = NULL;
	var->next = NULL;
}

void 		init_struct_var(t_farm **a, char **map_strngs, int str_indx)
{
	int 	i;

	i = str_indx;
	if (ft_strnstr(map_strngs[i], "start", 5))
	{
		(*a)->room_name = (char *)ft_memalloc(sizeof(char) * 6);
		(*a)->room_name = ft_strcpy((*a)->room_name, "start\0");
	}
	else if (ft_strnstr(map_strngs[i], "end", 3))
	{
		(*a)->room_name = (char *)ft_memalloc(sizeof(char) * 3);
		(*a)->room_name = ft_strcpy((*a)->room_name, "end\0");
	}
	else if (ft_isdigit(map_strngs[i][0]))
	{
		(*a)->room_name = (char *)ft_memalloc((sizeof(char)) + sizeof(char));
		(*a)->room_name[0] = map_strngs[i][0];
		(*a)->room_name[1] = '\0';
	}
}

void 		make_list(t_farm **a, t_farm *head, char **map_strngs, int total_rooms)
{
	t_farm 	temp;
	int 	i;
	int 	x;

	i = 1;
	x = 0;
	null_var(&temp);
	while (x < total_rooms)
	{
		if ((ft_isdigit(map_strngs[i][0]) || map_strngs[i][0] == 's' ||
		     map_strngs[i][0] == 'e') && map_strngs[i][1] != '-')
		{
			if (!((*a) = (t_farm*)malloc(sizeof(t_farm))))
				exit(0);
			init_struct_var(a, map_strngs, i);
			if (head->next == NULL)
				head->next = (*a);
			(*a)->next = temp.next;
			temp.next = (*a);
			x++;
		}
		i++;
	}
}

void 		create_antfarm(char **map_strngs, int total_rooms, int total_ants)
{
	t_farm 	*a;
	t_farm	head;

	a = NULL;
	null_var(&head);
	make_list(&a, &head, map_strngs, total_rooms);
	while (a != NULL)
	{
		ft_putendl(a->room_name);
		a = a->next;
	}
	a = head.next;
	exit(0);
}