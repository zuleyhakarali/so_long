/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:31:50 by zkarali           #+#    #+#             */
/*   Updated: 2025/07/06 14:54:40 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_nbr(va_arg(args, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_hex(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_hex(va_arg(args, unsigned int), 'X'));
	return (0);
}
