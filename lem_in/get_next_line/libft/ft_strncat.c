/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:14:01 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:47:19 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	counta;
	size_t	len;

	counta = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1);
	while (s2[counta] != '\0' && counta < n)
	{
		s1[len] = s2[counta];
		counta++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
