/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:46:34 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:35:17 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counta;
	unsigned char	*new_str;
	unsigned char	new_a;

	counta = 0;
	new_str = (unsigned char*)s;
	new_a = (unsigned char)c;
	while (counta < n)
	{
		if (new_str[counta] == new_a)
			return (new_str + counta);
		counta++;
	}
	return (0);
}
