/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 08:19:17 by aamoussa          #+#    #+#             */
/*   Updated: 2021/12/12 15:25:16 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_puthexa(unsigned int nb, char c, int *len)
{
	char			*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, c, len);
		ft_puthexa(nb % 16, c, len);
	}
	else
	{
		*len += ft_putchar(base[nb]);
	}
}

void	ft_put_p(unsigned long nb, int *len)
{
	char			*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_put_p(nb / 16, len);
		ft_put_p(nb % 16, len);
	}
	else
	{
		*len += ft_putchar(base[nb]);
	}
}

void	ft_putnbr(long long nb, int *len)
{
	size_t	nb2;

	if (nb < 0)
	{
		*len += ft_putchar('-');
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
	if (!str)
	{	
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i] != 0)
	{
		*len += ft_putchar(str[i]);
		i++;
	}
}
