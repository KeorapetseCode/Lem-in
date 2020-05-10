/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:24:56 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/27 15:22:36 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	counta;

	counta = 0;
	if (!(s) || !(f))
		return ;
	while (s[counta] != '\0')
	{
		f(counta, &s[counta]);
		counta++;
	}
}
