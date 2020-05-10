/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:14:56 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/27 15:17:01 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			counta;

	counta = 0;
	new_s1 = (unsigned char*)s1;
	new_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((s1[counta] != '\0' && s2[counta] != '\0') &&
			(s1[counta] == s2[counta]) && (counta < n - 1))
		counta++;
	return (new_s1[counta] - new_s2[counta]);
}
