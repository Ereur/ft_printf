/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:47:43 by aamoussa          #+#    #+#             */
/*   Updated: 2021/12/12 16:47:51 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
void	ft_putnbr(long long nb, int *len);
void	ft_putstr(char *str, int *len);
void	ft_puthexa(unsigned int nb, char c, int *len);
int		ft_printf(const char *str, ...);
void	ft_put_p(unsigned long nb, int *len);
#endif
