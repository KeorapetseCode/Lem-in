/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:02:58 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 14:28:43 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counta;
	char	*new_s;

	new_s = (char*)s;
	counta = 0;
	while (counta < n)
	{
		new_s[counta] = 0;
		counta++;
	}
}
