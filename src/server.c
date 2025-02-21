/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:06:02 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/21 16:13:11 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int sig, siginfo_t *info, void *vptr)
{
	static char	value = 0;
	static int	count = 0;

	value = (value << 1) | (sig == SIGUSR1);
	count++;
	if (count == 8)
	{
		ft_putchar_fd(value, STDOUT_FILENO);
		value = 0;
		count = 0;
	}
	kill(info->si_pid, SIGUSR1);
	(void)vptr;
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.__sigaction_u.__sa_sigaction = handler;
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
