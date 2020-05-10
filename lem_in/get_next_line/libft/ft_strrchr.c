/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:12:42 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:51:33 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counta;
	int		s_length;

	counta = 0;
	s_length = ft_strlen(s);
	if (c == 0)
	{
		while (s[counta] != '\0')
			counta++;
		return ((char*)s + counta);
	}
	else
	{
		while (s_length >= 0)
		{
			if (s[s_length] == (char)c)
				return ((char*)s + s_length);
			s_length--;
		}
	}
	return (0);
}
