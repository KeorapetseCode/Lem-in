/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:54:49 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/07/09 10:58:34 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_searcha(int fd, char **str)
{
	int		returna;

	returna = 0;
	while (str[fd][returna] != '\0' && str[fd][returna] != '\n')
		returna++;
	return (returna);
}

static char		*ft_reader(int fd, char **str, char **line)
{
	int				counta;
	char			*temp_hold;

	counta = ft_searcha(fd, str);
	if (str[fd][counta] == '\n')
	{
		*line = ft_strsub(str[fd], 0, counta);
		temp_hold = ft_strdup(str[fd] + counta + 1);
		free(str[fd]);
		str[fd] = temp_hold;
	}
	else if (str[fd][counta] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (*line);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	char			*temp_hold;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (str[fd] == NULL)
			str[fd] = ft_strnew(ret);
		buff[ret] = '\0';
		temp_hold = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp_hold;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if ((ret == 0 && str[fd] == NULL) || str[fd][0] == '\0')
		return (0);
	*line = ft_reader(fd, str, line);
	return (1);
}
