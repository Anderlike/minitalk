/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:50:31 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/02/17 14:52:01 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/minitalk.h"

volatile sig_atomic_t ack_received = 0;

void    ft_error(void)
{
    ft_printf("Error\n");
    exit(0);
}


void ack_handler(int signal)
{
    (void)signal;
    ack_received = 1;
}

void ft_send_bits(int pid, char i)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((i & (0x01 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        bit++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = atoi(argv[1]);
        signal(SIGUSR1, ack_handler);
        while (argv[2][i] != '\0')
        {
            ack_received = 0;
            ft_send_bits(pid, argv[2][i]);
            while (!ack_received)
                usleep(100);
            i++;
        }
        ack_received = 0;
        ft_send_bits(pid, '\n');
        while (!ack_received)
            usleep(100);
    }
    else
        ft_error();
    return (0);
}
