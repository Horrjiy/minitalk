/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:42:06 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/21 16:44:02 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler_answer(int sig)
{
	(void)sig;
}

void	sendchar(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		pause();
	}
}

int	main(int argc, char *argv[])
{
	char	*text;
	int		pid;

	if (argc != 3)
		return (ft_printf("Error\npid and string needed!"), 1);
	if (ft_strlen(argv[1]) < 1 || ft_strlen(argv[1]) > 5)
		return (ft_printf("Error\npid too long"), 1);
	if (ft_isdigit_str(argv[1]) == 0)
		return (ft_printf("Error\ninvalid pid"), 1);
	pid = (pid_t)atoi(argv[1]);
	text = argv[2];
	signal(SIGUSR1, handler_answer);
	signal(SIGUSR2, handler_answer);
	while (*text)
	{
		sendchar(pid, *text);
		text++;
	}
	return (0);
}
