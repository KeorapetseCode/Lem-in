/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:13:21 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:25:22 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counta;
	char	*new_b;

	counta = 0;
	new_b = (char*)b;
	while (counta < len)
	{
		new_b[counta] = c;
		counta++;
	}
	return (new_b);
}
