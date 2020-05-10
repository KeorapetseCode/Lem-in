/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:07:33 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/25 09:24:14 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	counta;
	size_t	returna;

	returna = 0;
	counta = 0;
	len_dst = 0;
	len_src = 0;
	while (dst[len_dst] != '\0')
		len_dst++;
	while (src[len_src] != '\0')
		len_src++;
	if (dstsize <= len_dst)
		returna = len_src + dstsize;
	else
		returna = len_dst + len_src;
	while (dstsize > len_dst + 1 && src[counta] != '\0')
	{
		dst[len_dst] = src[counta];
		len_dst++;
		counta++;
	}
	dst[len_dst] = '\0';
	return (returna);
}
