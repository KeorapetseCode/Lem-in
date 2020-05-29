#include "lem_in.h"

char	*make_node_2(const char *s, char c)
{
	int		a;
	size_t 	i;
	int 	temp;
	char	*ret;

	a = 0;
	i = 0;
	ret = NULL;
	while (s[a] != '\0')
	{
		if (s[a] == c)
		{
			a += 1;
			temp = a;
			while(s[a] != '\0')
			{
				if (ft_isprint(s[a]))
					i++;
				a++;
			}
			ret = (char *)malloc((sizeof(char) * i) + sizeof(char));
			a = temp;
			i = 0;
			while (s[a] != '\0')
			{
				if (ft_isprint(s[a]))
					ret[i] = s[a]; 
				i++;
				a++;
			}
			ret[i] = '\0';
			return (ret);
		}
		else if (s[a] == '\0')
			return (NULL); 
		a++;
	}
	return (NULL);
}


char	*room_writer(const char *s, char c)
{
	int		a;
	int 	i;
	char	*ret;

	a = 0;
	i = 0;
	ret = NULL;
	while (1)
	{
		if (s[a] == c)
		{
			ret = (char *)malloc((sizeof(char) * a) + sizeof(char));
			while (i < a)
			{
				ret[i] = s[i];
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
		else if (s[a] == '\0')
			return (NULL); 
		a++;
	}
	return (NULL);
}

void 		give_roomname(t_farm **a, char **map_strngs, int i)
{
	(*a)->room_name = NULL;

	if ((!ft_strchr(map_strngs[i], '#') && (!ft_strchr(map_strngs[i], '-'))))
	{
		if ((!ft_strnstr(map_strngs[i-1], "##start", 7)) &&
		    (!ft_strnstr(map_strngs[i-1], "##end", 5)))
		{
			if (ft_strchr(map_strngs[i], ' '))
				(*a)->room_name = room_writer(map_strngs[i], ' ');
			else
				(*a)->room_name = room_writer(map_strngs[i], '\0');				
			(*a)->room_id = -2;
		}
		else if (ft_strnstr(map_strngs[i], "start", 5))
		{
			if (ft_strchr(map_strngs[i], ' '))
				(*a)->room_name = room_writer(map_strngs[i], ' ');
			else
				(*a)->room_name = room_writer(map_strngs[i], '\0');
			(*a)->room_id = 1;
		}
		else if (ft_strnstr(map_strngs[i-1], "##start", 7))
		{
			if (ft_strchr(map_strngs[i], ' '))
				(*a)->room_name = room_writer(map_strngs[i], ' ');
			else
				(*a)->room_name = room_writer(map_strngs[i], '\0');
			(*a)->room_id = 1;
		}
		else if (ft_strnstr(map_strngs[i], "end", 3))
		{
			if (ft_strchr(map_strngs[i], ' '))
				(*a)->room_name = room_writer(map_strngs[i], ' ');
			else
				(*a)->room_name = room_writer(map_strngs[i], '\0');
			(*a)->room_id = 2;
		}
		else if (ft_strnstr(map_strngs[i-1], "##end", 5))
		{
			if (ft_strchr(map_strngs[i], ' '))
				(*a)->room_name = room_writer(map_strngs[i], ' ');
			else
				(*a)->room_name = room_writer(map_strngs[i], '\0');
			(*a)->room_id = 2;
		}
	}
}

void 		make_list(t_farm **a, t_farm *head, char **map_strngs, int total_r)
{
	t_farm 	temp;
	int 	i;
	int 	x;

	i = 1;
	x = 0;
	temp.next = NULL;
	if (total_r < 1)
	{
		ft_putendl("Not enough rooms");
		exit(0);
	}
	while (x < total_r)
	{
		if ((!ft_strchr(map_strngs[i], '#') && (!ft_strchr(map_strngs[i], '-'))))
		{
			if (!((*a) = (t_farm*)malloc(sizeof(t_farm))))
			{
				ft_putendl("Cannot Malloc For Rooms");
				exit(0);
			}
			(*a)->links = NULL;
			give_roomname(a, map_strngs, i);
			(*a)->next = temp.next;
			temp.next = (*a);
			x++;
			if (x == total_r)
				head->next = (*a);
		}
		i++;
	}
}