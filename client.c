#include "minitalk.h"

void send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
}

int main(int argc, char **argv)
{
    int i = -1;
    int pid = ft_atoi(argv[1]);

    if (argc != 3)
    {
        write(1, "Usage: ./client <PID> <Message>\n", 32);
        return 1;
    }

    if (pid <= 0)
    {
        write(1, "Invalid PID\n", 12);
        return 1;
    }

    char *message = argv[2];
    while  (message[++i])
        send_char(pid, message[i]);
    send_char(pid, '\0');
    return 0;
}