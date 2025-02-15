/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:42:06 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 21:54:33 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char *argv[])
{
	char				*text;
	struct sigaction	act;

	if (argc != 3 || ft_strlen(argv[2]) < 1 || ft_strlen(argv[2]) > 5)
		return (write(1, "Error\n", 6), 1);
	text = argv[2];
	while (*text)
	{
		kill((pid_t)atoi(argv[1]), SIGUSR1);
		text++;
	}
	return (0);
}
