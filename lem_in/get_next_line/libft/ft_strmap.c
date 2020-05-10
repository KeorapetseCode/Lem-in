/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:10:31 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/18 11:12:44 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		counta;
	char	*ret;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	counta = 0;
	if (!(ret = (char*)malloc(len + 1)))
		return (NULL);
	else
	{
		while (s[counta] != '\0')
		{
			ret[counta] = f(s[counta]);
			counta++;
		}
		ret[counta] = '\0';
	}
	return (ret);
}
