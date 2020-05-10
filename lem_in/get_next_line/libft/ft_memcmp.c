/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:56:33 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 15:20:34 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			s;
	size_t			counta;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	s = 0;
	counta = 0;
	new_s1 = (unsigned char*)s1;
	new_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (counta < n)
	{
		if (new_s1[counta] != new_s2[counta])
			return (new_s1[counta] - new_s2[counta]);
		counta++;
	}
	return (0);
}
