/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:59:57 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/23 16:01:33 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	calculate_atoi(const char *str, int sign)
{
	unsigned long	num;
	unsigned long	max;
	int				digit;

	num = 0;
	max = LLONG_MAX;
	if (sign == 1)
		digit = 7;
	else
		digit = 8;
	while (ft_isdigit(*str))
	{
		if (num < max / 10 || (num == max / 10 && *str - '0' <= digit))
			num = num * 10 + (*str - '0');
		else
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return ((int)num * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	return (calculate_atoi(str, sign));
}
