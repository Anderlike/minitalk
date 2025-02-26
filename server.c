/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:50:37 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/02/17 18:19:18 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/minitalk.h"

void	ft_handler(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	else if(signal == SIGUSR2)
		i &= ~(0x01 << bit);
	
	bit++;
	if (bit == 8)
	{
		if (i == '\n')
			write(1, "\n", 1);
		else
			write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting...\n");


	struct sigaction sa;
	sa.sa_handler = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
	{
		pause();
	}
	return (0);
}
