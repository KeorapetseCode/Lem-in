/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:02:10 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 09:04:16 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_digits(int num)
{
	unsigned int	ret;

	ret = 0;
	if (num >= 0 && num <= 9)
		return (1);
	while (num >= 10)
	{
		num = num / 10;
		ret = ret + 1;
	}
	return (ret + 1);
}
