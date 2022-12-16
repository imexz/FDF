/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:32:25 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/23 13:57:47 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_num_str(char const *s, char c)
{
	int		found;
	size_t	num_str;
	int		i;

	found = 0;
	num_str = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			found = 0;
		else if (found == 0)
		{
			num_str++;
			found = 1;
		}
		i++;
	}
	return (num_str);
}

static char	*ft_get_substr(char const *s, char c, size_t *pos)
{
	size_t	i;
	char	*substr;

	while (s[*pos] == c)
		(*pos)++;
	i = *pos;
	while (s[i] != c && s[i] != 0)
		i++;
	substr = ft_substr(s, *pos, i - *pos);
	if (substr == 0)
		return (0);
	*pos = i + 1;
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_str;
	char	**ret;
	size_t	i;
	char	*substr;
	size_t	pos;

	if (s == 0)
		return (0);
	num_str = ft_get_num_str(s, c);
	ret = ft_calloc(sizeof(char *), num_str + 1);
	if (ret == 0)
		return (0);
	i = 0;
	pos = 0;
	while (i < num_str)
	{
		substr = ft_get_substr(s, c, &pos);
		if (substr == 0)
			return (0);
		ret[i] = substr;
		i++;
	}
	ret[num_str] = NULL;
	return (ret);
}
