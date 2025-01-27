/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:33:19 by hajmoham          #+#    #+#             */
/*   Updated: 2025/01/26 18:39:14 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int sig)
{
    static char current_char = 0;
    static int bit_count = 0;

    if (sig == SIGUSR1)
        current_char |= (1 << (7 - bit_count));
    bit_count++;
    if (bit_count == 8)
    {
        write(1, &current_char, 1);
        if (current_char == '\0')
            write(1, "\n", 1);
        current_char = 0;
        bit_count = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    // write(1, "Server PID: ", 12);

    printf("Server PID: %d\n", pid);

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (1)
        pause();
    return 0;
}

