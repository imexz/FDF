/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:23:22 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/21 10:45:19 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*ret;

	if (!s1)
		return (0);
	while (check_trim(*s1, set))
		s1++;
	i = ft_strlen(s1);
	while (i && check_trim(s1[i - 1], set))
		i--;
	ret = malloc(i + 1);
	if (!ret)
		return (0);
	ret = ft_memcpy(ret, s1, i);
	ret[i] = 0;
	return (ret);
}
