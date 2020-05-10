/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:15:15 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 12:50:34 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	int				counta;
	int				ret;

	ret = 0;
	new_s1 = (unsigned char*)s1;
	new_s2 = (unsigned char*)s2;
	counta = 0;
	while (s1[counta] && s2[counta] && s1[counta] == s2[counta])
		counta++;
	ret = (new_s1[counta] - new_s2[counta]);
	return (ret);
}
