#include "lem_in.h"

int         ft_rooms_map(t_notes *map)
{
    int     i;
    t_notes *farm;

    i = 0;
    farm = map;
    while (farm)
    {
        if (ft_strchr(farm->note, ' '))
            i++;
        farm = farm->next;
    }
    return (i);
}

int         ft_dest_present(t_notes *map)
{
    int     i;
    size_t  len;
    t_notes *temp;

    i = 0;
    temp = map;
    while (temp != NULL)
    {
        len = ft_strlen(temp->note);
        if (len == 7 && !ft_strncmp(temp->note, "##start", 7))
            i++;
        else if (len == 5 && !ft_strncmp(temp->note, "##end", 5))
            i++;
        temp = temp->next;
    }
    return (i);
}

int         ft_link_map(t_notes *map)
{
    int     i;
    t_notes *farm;

    i = 0;
    farm = map;
    while (farm)
    {
        if (ft_strchr(farm->note, '-'))
            i++;
        farm = farm->next;
    }
    return (i);
}
