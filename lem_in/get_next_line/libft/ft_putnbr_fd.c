/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:22:17 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/23 16:21:53 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		counta;
	long	returna;
	char	a[10];

	counta = 0;
	returna = n;
	if (returna < 0)
	{
		ft_putchar_fd('-', fd);
		returna = -returna;
	}
	if (returna == 0)
		ft_putchar_fd('0', fd);
	while (returna > 0)
	{
		a[counta] = returna % 10 + 48;
		returna = returna / 10;
		counta++;
	}
	counta--;
	while (counta >= 0)
	{
		ft_putchar_fd(a[counta], fd);
		counta--;
	}
}
