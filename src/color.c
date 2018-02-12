/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:44:26 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/10 14:44:39 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

unsigned int		blend(unsigned int c1, unsigned int c2, char rgb)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	ret;

	r = (c1 / 0x10000 + c2 / 0x10000) / 2;
	g = ((c1 % 0x10000) / 0x100 + (c2 % 0x10000) / 0x100) / 2;
	b = (c1 % 0x100 + c2 % 0x100) / 2;
	if (rgb == 'r')
		return (r);
	else if (rgb == 'g')
		return (g);
	else if (rgb == 'b')
		return (b);
	ret = r << 16 | g << 8 | b;
	return (ret);
}
