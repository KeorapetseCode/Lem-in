/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:34:28 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 10:19:05 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh_str;
	char	*new_s;
	size_t	counta;

	counta = 0;
	if (!s)
		return (NULL);
	new_s = (char*)s;
	if (!(fresh_str = (char*)malloc(len + 1)))
		return (NULL);
	while (counta < len)
	{
		fresh_str[counta] = new_s[start];
		counta++;
		start++;
	}
	fresh_str[counta] = '\0';
	return (fresh_str);
}
