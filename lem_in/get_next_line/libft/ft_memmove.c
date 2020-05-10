/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:24:38 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/25 09:12:13 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counta;
	char	*new_dest;
	char	*new_src;

	counta = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	new_dest = (char*)dst;
	new_src = (char*)src;
	if (new_src < new_dest)
	{
		while (len--)
			new_dest[len] = new_src[len];
	}
	else
	{
		while (counta < len)
		{
			new_dest[counta] = new_src[counta];
			counta++;
		}
	}
	return (new_dest);
}
