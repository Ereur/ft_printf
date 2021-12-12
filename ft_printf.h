/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:31:17 by zoukaddo          #+#    #+#             */
/*   Updated: 2021/12/11 18:02:37 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include<unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
void	ft_putnbr(int nb, int *len);
void	ft_putstr(char *str, int *len);
void	ft_puthexa(size_t nb, char c);
int		ft_printf(const char *str, ...);
#endif
