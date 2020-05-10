/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:55:50 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/27 15:20:23 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int		counter;

	if (!(s) || !(f))
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		f(&s[counter]);
		counter++;
	}
}
