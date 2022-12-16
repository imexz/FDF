/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:52:54 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/22 14:58:29 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*s1_cpy;

	len = ft_strlen(s1) + 1;
	s1_cpy = (char *) ft_calloc(len, sizeof(char));
	if (s1_cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	return (s1_cpy);
}
