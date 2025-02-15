/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:06:02 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 21:02:31 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// void ft_handler(int signalnum)
// {
// 	write(1, "Got signal:", 11);
// 	ft_putnbr_fd(signalnum, 1);
// 	write(1, "\n", 1);
// }

void abc(int sig)
{
	ft_putnbr_fd(sig, 1);
	write(1, "\nBonobo\n", sizeof("\nBonobo\n"));
}

int	main(int argc, char *argv[])
{
	int	i;
	struct sigaction act;
	
	ft_putnbr_fd(getpid(), 1);
	(void)argc;
	(void)argv;
	(void)act;
	i = 0;
	while (1)
	{
		signal(SIGUSR1, abc);
		i = sleep(6000000);
		// if (i != 0)
	}
	return (0);
}
