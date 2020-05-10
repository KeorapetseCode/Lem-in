/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:34:06 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 12:52:45 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		counta;
	char	*str_ret;

	counta = 0;
	if (!(str_ret = (char*)malloc(ft_strlen(s1) + 1 * sizeof(char))))
		return (NULL);
	else
	{
		while (s1[counta] != '\0')
		{
			str_ret[counta] = s1[counta];
			counta++;
		}
		str_ret[counta] = '\0';
	}
	return (str_ret);
}
