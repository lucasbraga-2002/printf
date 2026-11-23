/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:16:38 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/23 20:06:36 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg (*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg (*args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg (*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg (*args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg (*args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg (*args, unsigned int)));
	if (c == 'X')
		return (ft_puthex(va_arg (*args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		result;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			result = ft_format(format[++i], &args);
		else
			result = ft_putchar(format[i]);
		if (result == -1)
		{
			count = -1;
			break ;
		}
		count += result;
		i++;
	}
	va_end (args);
	return (count);
}

/* #include <stdio.h>
int main(void)
{
    int result;
	int result1;
	int result2;
	int result3;
	int result4;

    result = ft_printf("Hello %% 42!");
    printf("\nRetorno: %d\n", result);
	
	result1 = ft_printf("Hello%%");
    printf("\nRetorno: %d\n", result1);
	
	result2 = ft_printf("%%");
    printf("\nRetorno: %d\n", result2);

	result3 = ft_printf("A%%B%%C");
    printf("\nRetorno: %d\n", result3);

	result4 = ft_printf("100%%");
    printf("\nRetorno: %d\n", result4);
    return (0);
} */