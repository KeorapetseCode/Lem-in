/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:28:39 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 13:08:48 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_string_alloc(const char *str, char c)
{
	int		i;
	char	**fresh_str;

	i = 0;
	if (!(str))
		return (NULL);
	while (*str != '\0')
	{
		if (*str != c && *str != '\0')
			i++;
		while (*str != c && *str != '\0')
		{
			str++;
			if (*str == '\0')
			{
				if (!(fresh_str = (char**)malloc(sizeof(char**) * (i + 1))))
					return (NULL);
				return (fresh_str);
			}
		}
		str++;
	}
	if (!(fresh_str = (char**)malloc(sizeof(char**) * (i + 1))))
		return (NULL);
	return (fresh_str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh_str;
	int		counta;
	int		start;
	int		i;

	start = 0;
	i = 0;
	counta = 0;
	if (!(s))
		return (NULL);
	if ((fresh_str = ft_string_alloc(s, c)) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			fresh_str[counta++] = ft_strsub(s, start, (i - start));
	}
	fresh_str[counta] = NULL;
	return (fresh_str);
}
