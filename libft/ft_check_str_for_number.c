/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str_for_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:11:27 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/17 16:47:00 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_str_for_number(char *s, int base)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	while (ft_isspace(s[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&s[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
		i++;
	while (ft_isdigit_base(s[i], base) >= 0)
	{
		i++;
		digits++;
	}
	if ((!s[i] || s[i] == '\n') && digits)
		return (1);
	else
		return (0);
}
