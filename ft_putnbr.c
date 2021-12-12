/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:24:33 by zoukaddo          #+#    #+#             */
/*   Updated: 2021/12/11 17:19:47 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
