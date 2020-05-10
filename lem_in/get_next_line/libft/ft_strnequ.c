/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:20:31 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/22 16:39:46 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		ret;
	size_t	counta;

	counta = 0;
	ret = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		n--;
		while ((s1[counta] && s2[counta]) && (s1[counta] == s2[counta]) && n--)
			counta++;
		ret = ((char)s1[counta] - (char)s2[counta]);
		if (ret == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
