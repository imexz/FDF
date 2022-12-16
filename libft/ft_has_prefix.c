/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:08:06 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/17 12:08:49 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_has_prefix(char *s, int base)
{
	int	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (s[i++] != '0')
			return (0);
		if (base == 2 && (s[i] == 'b' || s[i] == 'B'))
			return (1);
		if (base == 16 && (s[i] == 'x' || s[i] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}
