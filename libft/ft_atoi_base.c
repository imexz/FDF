/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:15:17 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/17 12:15:53 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(char *s, int base)
{
	unsigned long	result;
	int				i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&s[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i++] == '-')
			sign = (-1);
	}
	while (ft_isdigit_base(s[i], base) >= 0)
		result = result * base + ft_isdigit_base(s[i++], base);
	return ((int)(result * sign));
}
