/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:10:53 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 12:56:54 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
