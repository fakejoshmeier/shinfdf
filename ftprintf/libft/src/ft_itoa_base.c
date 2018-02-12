/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:35:33 by jmeier            #+#    #+#             */
/*   Updated: 2017/09/25 15:59:31 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n, int base)
{
	int		len;
	long	nb;

	len = 0;
	nb = (long)n;
	if (nb <= 0)
	{
		len++;
		nb *= -1;
	}
	while (nb != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}

char		*ft_itoa_base(int n, int base)
{
	char	*str;
	int		len;
	long	nb;

	len = numlen(n, base);
	nb = (long)n;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str[len--] = (nb % base) + '0';
	while (nb >= base)
	{
		nb /= base;
		str[len--] = (nb % base) + '0';
	}
	return (str);
}
