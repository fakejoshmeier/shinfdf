/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:19:51 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/09 19:24:34 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_longlen(long n, int base)
{
	int		len;
	long	nb;

	len = 0;
	nb = (long)n;
	if (nb <= 0)
		nb *= -1;
	while (nb != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}
