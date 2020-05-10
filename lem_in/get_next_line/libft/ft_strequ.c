/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:46:07 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 08:11:56 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		ret;
	int		counta;
	char	*new_s1;
	char	*new_s2;

	ret = 0;
	if (s1 && s2)
	{
		new_s1 = (char*)s1;
		new_s2 = (char*)s2;
		counta = 0;
		while ((s1[counta] && s2[counta]) && (s1[counta] == s2[counta]))
			counta++;
		ret = (new_s1[counta] - new_s2[counta]);
		if (ret == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
