/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:06:02 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 21:56:10 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// void ft_handler(int signalnum)
// {
// 	write(1, "Got signal:", 11);
// 	ft_putnbr_fd(signalnum, 1);
// 	write(1, "\n", 1);
// }

void	abc(int sig)
{
	ft_putnbr_fd(sig, 1);
	write(1, "\nBonobo\n", sizeof("\nBonobo\n"));
}

int	main(void)
{
	int	i;

	ft_putnbr_fd(getpid(), 1);
	i = 0;
	signal(SIGUSR1, abc);
	while (1)
		i = sleep(1);
	return (0);
}
