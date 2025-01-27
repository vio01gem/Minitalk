#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					sign;
	int					i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		if (sign == -1 && nb >= LLONG_MAX)
			return (0);
		if (nb >= LLONG_MAX)
			return (-1);
		i++;
	}
	return (sign * nb);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

