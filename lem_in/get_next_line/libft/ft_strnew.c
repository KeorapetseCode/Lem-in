/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:24:59 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/22 13:58:10 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_memory;
	size_t	counta;

	counta = 0;
	if (!(new_memory = (char*)malloc(size + 1)))
		return (NULL);
	while (counta < size)
	{
		new_memory[counta] = '\0';
		counta++;
	}
	new_memory[counta] = '\0';
	return (new_memory);
}
