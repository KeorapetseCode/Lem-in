/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:30:04 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/25 10:21:05 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		counta_1;
	int		counta_2;

	counta_1 = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (haystack[counta_1] != '\0')
	{
		counta_2 = 0;
		while ((needle[counta_2] == haystack[counta_1 + counta_2]))
		{
			if (needle[counta_2 + 1] == '\0')
				return ((char*)haystack + counta_1);
			counta_2++;
		}
		counta_1++;
	}
	return (0);
}
