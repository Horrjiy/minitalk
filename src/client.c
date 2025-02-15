/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:42:06 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 21:03:46 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char *argv[])
{
	char *text;
	if (argc != 3)
		return (write(1, "wrong input\n", 12), 1);
	text = argv[2];
	while()
	{
		kill((pid_t)atoi(argv[1]), SIGUSR1);
	}
	return (0);
}
