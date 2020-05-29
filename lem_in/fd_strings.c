#include "lem_in.h"

int 		map_valid(char **map_strngs)
{
	int 	a;
	int 	start;
	int 	end;
	int 	links;

	a = 0;
	start = 0;
	end = 0;
	links = 0;
	if (total_ants(map_strngs) < 1 )
		return (-1);
	if (!(ft_strchr(map_strngs[a], ' ')))
	{
		a++;
		while (map_strngs[a] != NULL)
		{
			if (ft_strnstr(map_strngs[a-1], "##start", 7))
				start++;
			else if (ft_strnstr(map_strngs[a-1], "##end", 5))
				end++;
			else if (ft_strchr(map_strngs[a], '-'))
				links++;
			a++;
		}
	}
/*	else
	{
		ft_putendl("strlen");
		ft_putnbr(ft_strlen(map_strngs[0]));
	}
*/	if ((start == 1) && (end == 1) && (links > 0) && (a > 1))
		return (links);
	return (-1);
}

char 		**ft_memwrite(int i, char **src)
{
	char 	**ret;
	int		a;
	size_t 	len;

	ret = NULL;
	a = 0;
	ret = (char**)malloc((sizeof(char*) * i) + sizeof(char *));
	while (src[a] != NULL)
	{
		len = ft_strlen(src[a]);
		ret[a] = (char*)ft_memalloc((sizeof(char) * len) + sizeof(char));
		ret[a] = ft_strcpy(ret[a], src[a]);
		a++;
	}
	ret[a] = NULL;
	return (ret);
}
int 		printable(char *input, int len)
{
	int 	i;

	i = 0;
	while (len < i)
	{
		if (ft_isprint(input[i]) == 0);
			return (-1);
		i++;
	}
	return (0);
}
char 		**fd_strings(int fd)
{
	char 	*input;
	char 	**new_str;
	size_t 	len;
	int		i;

	i = 0;
	new_str = NULL;
	while (1)
	{
		if (get_next_line(fd, &input))
		{
			len = ft_strlen(input);
			if (printable(input, len) == -1)
			{
				ft_putendl("One of the characters is not printable");
				exit(0);
			}
			if (i == 0)
				new_str = (char**)malloc(sizeof(char*) * 5000);
			new_str[i] = (char *)malloc((sizeof(char) * len) + sizeof(char));
			new_str[i] = ft_strcpy(new_str[i], input);
			i++;
		}
		else
		{
			if ((get_next_line(fd, &input) == 0) && (i < 6))
			{
				if (new_str != NULL)
					free(new_str);
				ft_putendl("Not enough rooms, ants or links");
				exit(0);
			}
			else
			{
				new_str[i] = NULL;
				new_str = ft_memwrite(i, new_str);
				return (new_str);
			}
		}
	}
}