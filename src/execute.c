#include "lem_in.h"

//Sets every pointer and integer to NULL and 0.
//As we are advised in C to set every pointer to NULL before we use it.
//keys is passed by refernce to this function, the reason being we change its variable properties.

void	ft_begin(t_keys *keys)
{
	t_keys	*key;

	key = keys;
	key->start = NULL;
	key->end = NULL;
	key->read = NULL;
	key->ants = 0;
	key->rooms = 0;
	key->room_counter = 0;
}

void	ft_check_start_end(t_keys *keys)
{
	if (keys->start == NULL || keys->end == NULL)
	{
        ft_putstr("ERROR\n");
        exit(0);
    }
}


//_____________________________________________________________________________________
//Checks the first line of the input file.
//if it finds a number less than 0 or Something other than a comment it prints ERROR
//If it finds a number greater than zero and lesser than int_max it prints it on the standard output.

void	ft_num_of_ants(t_keys *keys)
{
	char	*line;

	while(get_next_line(0, &line) == 1)
	{
		if(ft_int_max(line) && ft_atoi(line) > 0)
		{
			keys->ants = ft_atoi(line);
			free(line);
			break ;
		}
		else
		{
			if (line[0] != '#')
			{
                ft_putstr("ERROR\n");
                exit(0);
            }
		}
		free(line);
	}
	ft_putnbr(keys->ants);
	ft_putchar('\n');
}