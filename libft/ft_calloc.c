/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:27:42 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/22 14:43:14 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	size_in_bytes;
	size_t	i;

	size_in_bytes = nitems * size;
	ptr = (char *) malloc(size_in_bytes);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (size_in_bytes))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
