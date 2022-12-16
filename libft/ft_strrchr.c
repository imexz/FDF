/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:11:38 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/22 15:00:59 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	rev_index;

	rev_index = (int) ft_strlen(str);
	while (rev_index >= 0)
	{
		if (((unsigned char *)str)[rev_index] == (unsigned char) c)
			return ((char *)&str[rev_index]);
		rev_index--;
	}
	return (NULL);
}
