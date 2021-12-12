/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:54:57 by zoukaddo          #+#    #+#             */
/*   Updated: 2021/12/12 08:15:06 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specificator(va_list ap, const char *str, int *len)
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
		ft_puthexa(va_arg(ap, size_t), str[0]);
	}
	else if (str[0] == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (str[0] == 'u')
		ft_putnbr(va_arg(ap, int), len);
	else if (str[0] == 'x')
		ft_puthexa(va_arg(ap, size_t), str[0]);
	else if (str[0] == 'X')
		ft_puthexa(va_arg(ap, size_t), str[0]);
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
// 	int	len;

// 	//  len = ft_printf(" %c %c", '0', 0, '1');
// 	// printf("\n%d\n", len);
// 	len = printf(" %c %c %c ", '0', 0, '1');
// 	printf("\n%d", len);
// }
