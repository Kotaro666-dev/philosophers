/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:12:27 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 12:56:57 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	length;

	length = ft_strlen(str);
	if (length != 0)
	{
		write(fd, str, length);
	}
}
