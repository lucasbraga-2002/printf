/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:01 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/24 17:48:30 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	result;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		result = ft_putchar(s[i]);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
