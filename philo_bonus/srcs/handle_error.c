/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:07:43 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/23 16:20:16 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	perror_and_exit(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	exit(1);
}
