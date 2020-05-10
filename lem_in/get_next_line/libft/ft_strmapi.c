/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:28:31 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/14 15:06:52 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			ret[counta] = f(counta, s[counta]);
			counta++;
		}
		ret[counta] = '\0';
	}
	return (ret);
}
