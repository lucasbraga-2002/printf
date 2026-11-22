/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:22:48 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/22 22:13:05 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    int result;
    
    result = write(1, &c, 1);
    if (result != 1)
        return (-1);
    return (1);
}

/* int ft_putchar(char c)
{
    return((int)write(1, &c, 1));
} */