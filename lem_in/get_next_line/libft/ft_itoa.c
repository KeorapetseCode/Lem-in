/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:47:11 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/19 16:40:57 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*fresh_str;
	int		neg;
	int		num_digit;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	num_digit = ft_num_digits(n) + neg;
	if (!(fresh_str = (char*)malloc(num_digit + 1)))
		return (NULL);
	fresh_str[num_digit] = '\0';
	while (num_digit-- != -1)
	{
		fresh_str[num_digit] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg == 1)
		fresh_str[0] = '-';
	return (fresh_str);
}
