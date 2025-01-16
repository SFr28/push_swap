/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:16:22 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/27 11:24:37 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_puthexa_count(unsigned int nb, char c);
int	ft_putunbr_count(unsigned int n);
int	ft_putptr_count(unsigned long ptr);
int	ft_putnbr_count(int nb);
int	ft_putstr_count(char *str);
int	ft_putchar_count(char c);
int	ft_printf(const char *s, ...);

#endif
