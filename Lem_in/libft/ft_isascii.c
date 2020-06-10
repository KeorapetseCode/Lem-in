/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:56:33 by mdube             #+#    #+#             */
/*   Updated: 2019/06/05 17:14:31 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isascii(int c)
{
	int		output;

	if (c >= 000 && c <= 0117)
		output = 1;
	else if (c >= 0 && c <= 127)
		output = 1;
	else
		output = 0;
	return (output);
}