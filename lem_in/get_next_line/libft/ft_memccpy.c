/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:42:23 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:31:32 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				counta;
	unsigned char		*new_dest;
	unsigned char		*new_src;

	counta = 0;
	new_dest = (unsigned char*)dst;
	new_src = (unsigned char*)src;
	while (counta < n)
	{
		new_dest[counta] = new_src[counta];
		if (new_src[counta] == (unsigned char)c)
			return (new_dest + counta + 1);
		counta++;
	}
	return (0);
}
