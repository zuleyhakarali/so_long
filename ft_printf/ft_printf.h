/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:31:46 by zkarali           #+#    #+#             */
/*   Updated: 2025/07/06 14:56:29 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list args, char c);
int	ft_char(char c);
int	ft_str(char *s);
int	ft_nbr(int n);
int	ft_unsigned(unsigned int n);
int	ft_hex(unsigned int n, char c);
int	ft_pointer(void *p);

#endif