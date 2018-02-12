/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:57:21 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/08 22:23:37 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ss1(t_bres breezy)
{
	if (breezy.swap)
		breezy.a.x += breezy.sx;
	else
		breezy.a.y += breezy.sy;
	breezy.err -= 2 * breezy.dx;
}

void	ss2(t_bres breezy)
{
	if (breezy.swap)
		breezy.a.y += breezy.sy;
	else
		breezy.a.x += breezy.sx;
	breezy.err += 2 * breezy.dy;
}
