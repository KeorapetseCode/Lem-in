/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:50:29 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:44:25 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	counta;
	int	len;

	counta = 0;
	len = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	while (s2[counta] != '\0')
	{
		s1[len] = s2[counta];
		counta++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
