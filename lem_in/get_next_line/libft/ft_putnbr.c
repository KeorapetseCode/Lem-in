/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:37:55 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 16:32:36 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	a[10];
	long	returna;
	int		counta;

	counta = 0;
	returna = n;
	if (returna < 0)
	{
		ft_putchar('-');
		returna = -returna;
	}
	if (returna == 0)
		ft_putchar('0');
	while (returna > 0)
	{
		a[counta] = returna % 10 + 48;
		returna = returna / 10;
		counta++;
	}
	while (--counta >= 0)
		ft_putchar(a[counta]);
}
