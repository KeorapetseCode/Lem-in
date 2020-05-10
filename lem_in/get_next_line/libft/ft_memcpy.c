/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:03:55 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:30:12 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counta;
	char	*new_src;
	char	*new_dest;

	counta = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	new_dest = (char*)dst;
	new_src = (char*)src;
	while (counta < n)
	{
		new_dest[counta] = new_src[counta];
		counta++;
	}
	return (new_dest);
}
