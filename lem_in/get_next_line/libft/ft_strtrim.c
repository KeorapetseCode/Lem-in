/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmpoloke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:50:23 by kmpoloke          #+#    #+#             */
/*   Updated: 2019/06/28 13:08:20 by kmpoloke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*fresh_str;
	size_t			len;
	size_t			start;

	start = 0;
	if (!(s))
		return (NULL);
	if (!(*s))
		return ("\0");
	len = ft_strlen(s);
	if (len == 0)
		return ("\0");
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(&s[start]));
	if (s[len] == '\0')
		len = len - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len = len + 1;
	fresh_str = ft_strsub(s, start, (len - start));
	if (fresh_str == NULL)
		return (NULL);
	return (fresh_str);
}
