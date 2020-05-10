/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:42:12 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/19 17:40:39 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counta;
	char	*fresh_str;

	counta = 0;
	if (!(s1 && s2))
		return (NULL);
	if (!(fresh_str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	else
	{
		while (s1[counta] != '\0')
		{
			fresh_str[counta] = s1[counta];
			counta++;
		}
		while (*s2 != '\0')
		{
			fresh_str[counta] = *s2;
			counta++;
			s2++;
		}
		fresh_str[counta] = '\0';
	}
	return (fresh_str);
}
