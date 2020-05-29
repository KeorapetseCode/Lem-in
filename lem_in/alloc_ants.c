#include "lem_in.h"


void 	alloc_totalants(t_farm **a, t_farm *head, char **map_strngs)
{
	int 	total;

	total = total_ants(map_strngs);
	(*a) = head->next;
	while ((*a) != NULL)
	{
		if ((*a)->room_id > 0)
		{
			if (!((*a)->ant = (char**)malloc((sizeof(char*) * total) + sizeof(char*))))
			{
				ft_putendl("Cannot Malloc Number of Ants");
				exit(0);
			}
		}
		else if ((*a)->room_id < 0)
		{
			if (!((*a)->ant = (char**)malloc((sizeof(char*) * 1) + sizeof(char*))))
			{
				ft_putendl("Cannot Malloc For Single Ant");
				exit(0);
			}
		}
		(*a) = (*a)->next;
	}
	(*a) = head->next;
}


void 	alloc_each_ant(t_farm **a, t_farm *head, char **map_strngs)
{
	while ((*a) != NULL)
	{
		if ((*a)->room_id < 0)
		{
			if (!((*a)->ant[0] = (char*)malloc(sizeof(char) * 1000)))
			{
				ft_putendl("Cannot Alloc for each ant");
				exit(0);
			}
			(*a)->ant[1] = NULL;
		}
		(*a) = (*a)->next;
	}
	(*a) = head->next;
}

void 	alloc_start_end(t_farm **a, t_farm *head, char **map_strngs)
{
	int 	i;
	int 	total;

	i = 0;
	total = total_ants(map_strngs);
	while ((*a) != NULL)
	{
		if ((*a)->room_id > 0)
		{
			while (i < total)
			{
				if (!((*a)->ant[i] = (char*)malloc((sizeof(char) * 1))))
				{
					ft_putendl("Cannot Malloc Ant string");
					exit(0);
				}
				if ((*a)->room_id == 1)
					(*a)->ant[i] = ft_itoa(i+1);
				i++;
			}
			(*a)->ant[i] = NULL;
			i = 0;
		}
		(*a) = (*a)->next;
	}
	(*a) = head->next;
	return ;
}

void	ants_alloc(t_farm **a, t_farm *head, char **map_strngs)
{
	alloc_totalants(a, head, map_strngs);
//	Reason i do not alloc for each ant (string) it's because ft_itoa() handles that
//	alloc_each_ant(a, head, map_strngs);
	alloc_start_end(a, head, map_strngs);
}