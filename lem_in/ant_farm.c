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
	size_t 	len;

	i = 1;
	len = ft_strlen(map_strngs[str_indx]);
	(*a)->room_name = (char *)ft_memalloc((sizeof(char) * len) + sizeof(char));
	(*a)->room_name = ft_strcpy((*a)->room_name, map_strngs[str_indx]);
/*	if (ft_strncmp((*a)->room_name, "Start", 5))
	{
		ft_putendl("Found Start****");
		ft_putnbr(str_indx);
		exit(0);
	}
	*/
}

void 		make_list(t_farm **a, t_farm *head, char **map_strngs, int total_rooms)
{
	t_farm 	temp;
	int 	i;
	int 	x;

	i = 1;
	x = 0;
	null_ptr(&temp);
	while (x < total_rooms)
	{
		if ((ft_isdigit(map_strngs[i][0]) || map_strngs[i][0] == 's'||
		    map_strngs[i][0] == 'S' || map_strngs[i][0] == 'e' ||
		    map_strngs[i][0] == 'E') && map_strngs[i][1] != '-')
		{
			if (!(*a) = (t_farm*)ft_memalloc(sizeof(t_farm)))
				exit(0);
			init_struct_var(a, map_strngs);
			if (head->next == NULL && (*a)->next == NULL)
				head->next = (*a);
			temp.next = (*a);
			(*a)->next = temp.next;
			x++;
		}
		i++;
	}
}

void 		create_antfarm(char **map_strngs, int total_rooms, int total_ants)
{
	t_farm 	*a;
	t_farm	head;

	null_ptr(&a);
	null_ptr(&head);
	make_list(&a, &head, map_strngs, total_rooms);

}