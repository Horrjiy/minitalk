/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:06:02 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/27 19:58:27 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	handler(int sig, siginfo_t *info, void *vptr)
{
	static char	value = 0;
	static int	count = 0;

	usleep(25);
	value = (value << 1) | (sig == SIGUSR1);
	count++;
	if (count == 8)
	{
		ft_putchar_fd(value, STDOUT_FILENO);
		if (value == '\0')
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_error("kill failed");
			value = 0;
			count = 0;
			return ;
		}
		value = 0;
		count = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error("kill failed");
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
