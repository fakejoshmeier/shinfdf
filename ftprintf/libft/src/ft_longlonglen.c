/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:19:51 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/12 21:33:44 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_longlonglen(long long n, int base)
{
	int			len;
	long long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
		nb *= -1;
	while (nb != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}
