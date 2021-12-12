/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 08:19:17 by aamoussa          #+#    #+#             */
/*   Updated: 2021/12/12 08:20:51 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	if (c == 0)
		return (0);
	return (1);
}

void	ft_puthexa(size_t nb, char c)
{
	char			*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, c);
		ft_puthexa(nb % 16, c);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

void	ft_putnbr(int nb, int *len)
{
	unsigned int	nb2;

	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	nb2 = nb;
	if (nb2 >= 10)
	{
		ft_putnbr(nb2 / 10, len);
		ft_putnbr(nb2 % 10, len);
	}
	else
	{
		nb2 = nb2 + '0';
		*len += ft_putchar(nb2);
	}	
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		*len += ft_putchar(str[i]);
		i++;
	}
}
