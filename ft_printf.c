/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:54:57 by zoukaddo          #+#    #+#             */
/*   Updated: 2021/12/12 15:21:44 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_un(unsigned int nbr, int *len)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	else
	{
		nbr = nbr + '0';
		*len += ft_putchar(nbr);
	}	
}

static int	ft_specificator(va_list ap, const char *str, int *len)
{
	if (str[0] == 'd')
		ft_putnbr(va_arg(ap, int), len);
	else if (str[0] == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (str[0] == 'c')
		*len += ft_putchar(va_arg(ap, int));
	else if (str[0] == 'p')
	{	
		ft_putstr("0x", len);
		ft_put_p(va_arg(ap, unsigned long), len);
	}
	else if (str[0] == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (str[0] == 'u')
		ft_put_un(va_arg(ap, unsigned int), len);
	else if (str[0] == 'x')
		ft_puthexa(va_arg(ap, unsigned int), str[0], len);
	else if (str[0] == 'X')
		ft_puthexa(va_arg(ap, unsigned int), str[0], len);
	else if (str[0] == '%')
		*len += ft_putchar(str[0]);
	else
	{	
		*len += ft_putchar(str[0]);
		return (0);
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		len;

	len = 0;
	va_start (ap, str);
	while (*str)
	{
		i = 0;
		while (*str == '%')
		{	
			i = 0;
			i = ft_specificator(ap, ++str, &len);
			if (i)
				++str;
		}
		if (*str)
			len += ft_putchar(*(str++));
	}
	return (len);
}

// int main()
// {	
// 	int len;
// 	len = print(" %p %p ", LONG_MIN, LONG_MAX);
// 	printf("\nlen : %d\n",len);
// 	// len = ft_printf(" NULL %s NULL ", NULL);
// 	// printf("\n%d", len);
// }
