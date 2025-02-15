/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:06:02 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 16:16:45 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char *argv[])
{
	int	i;

	ft_putnbr_fd(getpid(), 1);
	(void)argc;
	(void)argv;
	i = 0;
	while (1)
	{
		i = sleep(6000000);
		if (i != 0)
			ft_printf("shit");
	}
	return (0);
}
