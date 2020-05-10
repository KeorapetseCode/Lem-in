/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:18:47 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:41:24 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	counta;

	counta = 0;
	while (counta < len && src[counta] != '\0')
	{
		dst[counta] = src[counta];
		counta++;
	}
	while (counta < len)
	{
		dst[counta] = 0;
		counta++;
	}
	return (dst);
}
