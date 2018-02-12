/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:46:49 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/09 16:14:55 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fillin(t_bres *ret)
{
	ret->dx1 = ret->w < 0 ? -1 : 1;
	ret->dy1 = ret->h < 0 ? -1 : 1;
	ret->dx2 = ret->w < 0 ? -1 : 1;
	ret->longest = ret->w > 0 ?  ret->w : -1 * ret->w;
	ret->shortest = ret->h > 0 ? ret->h : -1 * ret->h;
	if (ret->longest < ret->shortest)
	{
		ret->longest = ret->h > 0 ? ret->h : -1 * ret->h;
		ret->shortest = ret->w > 0 ? ret->w : -1 * ret->w;
		ret->dy2 = ret->h < 0 ? -1 : 1;
		ret->dx2 = 0;
	}
}

t_bres	bresenham(t_jig a, t_jig b)
{
	t_bres	ret;

	ret.a = a;
	ret.b = b;
	ret.x0 = a.x;
	ret.y0 = a.y;
	ret.x1 = b.x;
	ret.y1 = b.y;
	ret.i = -1;
	ret.w = ret.x1 - ret.x0;
	ret.h = ret.y1 - ret.y0;
	ret.dx1 = 0;
	ret.dy1 = 0;
	ret.dx2 = 0;
	ret.dy2 = 0;
	fillin(&ret);
	return (ret);
}

int		find_pos(t_xyz *fdf, int x, int y)
{
	int		pos;

	pos = 0;
	if ((x > 0 && y > 0) && (x < W_WIDTH && y < W_HEIGHT))
		pos = x + (y * fdf->s_line / 4);
	return (pos);
}
