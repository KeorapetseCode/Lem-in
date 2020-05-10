/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:21:26 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/14 11:28:33 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new_memory;
	size_t	i;

	i = 0;
	if (!(new_memory = (char*)malloc(size)))
		return (NULL);
	else
	{
		new_memory = (char*)malloc(size);
		while (i != size)
		{
			new_memory[i] = 0;
			i++;
		}
		return (new_memory);
	}
	return (new_memory);
}
