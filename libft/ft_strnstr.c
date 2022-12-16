/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:11:30 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/22 15:00:05 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*needle_start;

	i = 0;
	if (!needle[i])
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		needle_start = &((char *)haystack)[i];
		while (i + j < len && haystack[i + j] && needle[j]
			&& haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return (needle_start);
		i++;
	}
	return (NULL);
}
