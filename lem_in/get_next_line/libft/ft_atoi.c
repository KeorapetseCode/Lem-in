/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:02:26 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 11:54:01 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		returna;
	int		neg;

	returna = 0;
	neg = 1;
	if (!(*str))
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		returna = (returna * 10) + (*str - 48);
		str++;
	}
	return (returna * neg);
}
