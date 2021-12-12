/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:35:49 by aamoussa          #+#    #+#             */
/*   Updated: 2021/12/11 17:19:38 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
