/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:52:11 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:51:10 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		counta;
	char	new_c;

	counta = 0;
	new_c = (char)c;
	if (c == 0)
	{
		while (s[counta] != '\0')
			counta++;
		return ((char*)s + counta);
	}
	else
	{
		while (s[counta] != '\0')
		{
			if (s[counta] == c)
				return ((char*)s + counta);
			counta++;
		}
		return (0);
	}
}
