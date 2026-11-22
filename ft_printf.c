/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:16:38 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/22 22:29:45 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && (format[i + 1] == '%'))
		{
			i++;
			ft_putchar(format[i]);
			i++;
			count++;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
	}
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