/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:31:15 by tszymans          #+#    #+#             */
/*   Updated: 2023/12/03 20:45:38 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_checkbase(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (str[0] == '\0' || len == 1)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (1);
		j = i + 1;
		while (j <= len)
		{
			if (str[i] == str [j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;

	len = ft_strlen(base);
	if (ft_checkbase(base) == 0)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putchar('2');
			ft_putnbr_base(147483648, base);
		}
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if (nbr < len)
			ft_putchar(base[nbr]);
		if (nbr >= len)
		{
			ft_putnbr_base(nbr / len, base);
			ft_putnbr_base(nbr % len, base);
		}
	}
}
/*
#include <stdio.h>
int	main(void)
{
	//binary
	printf("%s\n", "********binary********");
	ft_putnbr_base(-2, "01");
	printf("\n");
	ft_putnbr_base(1, "01");
	printf("\n");
	ft_putnbr_base(29, "01");
	printf("\n");
	//octagonal
	printf("%s\n", "********octa********");
	ft_putnbr_base(-5, "poneyvif");
	printf("\n");
	ft_putnbr_base(7, "poneyvif");
	printf("\n");
	ft_putnbr_base(15, "poneyvif");
	printf("\n");
	//decimal
	printf("%s\n", "********decimal********");
	ft_putnbr_base(-20, "0123456789");
	printf("\n");
	ft_putnbr_base(7, "0123456789");
	printf("\n");
	ft_putnbr_base(17, "0123456789");
	printf("\n");
	//hex
	printf("%s\n", "********hexagonal********");
	ft_putnbr_base(-20, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(10, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(20, "0123456789ABCDEF");
	printf("\n");
}*/
