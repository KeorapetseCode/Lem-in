/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:25:30 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:53:26 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counta_1;
	size_t	counta_2;

	counta_1 = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (counta_1 < len && haystack[counta_1] != '\0')
	{
		counta_2 = 0;
		while ((needle[counta_2] == haystack[counta_1 + counta_2])
				&& (counta_1 + counta_2 < len))
		{
			if (needle[counta_2 + 1] == '\0')
				return ((char*)haystack + counta_1);
			counta_2++;
		}
		counta_1++;
	}
	return (0);
}
