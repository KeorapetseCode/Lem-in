#include "lem_in.h"

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

char 		**fd_strings(int fd)
{
	char 	*input;
	char 	**new_str;
	size_t 	len;
	int		i;

	len = 0;
	i = 0;
	new_str = NULL;
	while (get_next_line(fd, &input))
	{
		len = ft_strlen(input);
		if (i == 0)
			new_str = (char**)malloc(sizeof(char*) * 1000);
		new_str[i] = (char *)ft_memalloc((sizeof(char) * len) + sizeof(char));
		new_str[i] = ft_strcpy(new_str[i], input);
		i++;
	}
	new_str[i] = NULL;
	ft_strdel(&input);
	return (ft_memwrite(i, new_str));
}


