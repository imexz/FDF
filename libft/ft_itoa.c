/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:34:19 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/25 19:24:08 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_n_zero(int n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(2);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	return (0);
}

static char	*ft_min_int(int n)
{
	char	*str;

	if (n == (-2147483648))
	{
		str = (char *) malloc(12);
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
		return (str);
	}
	return (0);
}

static int	ft_count_digits(int n, int sign)
{
	int		temp_n;
	int		len;

	len = 0;
	temp_n = n;
	while (temp_n)
	{
		temp_n /= 10;
		len++;
	}
	if (sign)
		len++;
	return (len);
}

static char	*ft_write_itoa(int n, int len, int sign)
{
	int		i;
	char	*str;

	len = ft_count_digits(n, sign);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		str[len - i - 1] = (n % 10) + 48;
		n /= 10;
		if (sign && i == len - 1)
		{
			str[0] = '-';
			break ;
		}
		i++;
	}
	str[len] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	len = 0;
	sign = 0;
	if (n == 0)
	{
		str = ft_n_zero(n);
		return (str);
	}
	if (n == -2147483648)
	{
		str = ft_min_int(n);
		return (str);
	}
	if (n < 0)
	{
		sign = 1;
		n *= (-1);
	}
	str = ft_write_itoa(n, len, sign);
	if (!str)
		return (0);
	return (str);
}
