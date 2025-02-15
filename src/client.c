/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:42:06 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 16:26:37 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
		return(write(1, "wrong input\n", 13), 1);
	(void)argv;
	return(0);
}
