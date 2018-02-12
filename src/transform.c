/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:46:11 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/09 01:27:30 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	scale(t_xyz *fdf)
{
	int		r;
	int		c;
	double	xs;
	double	ys;

	r = -1;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			xs = (fdf->twist[r][c].x * (fdf->size / (fdf->col + 1)) / 2) *
				(fdf->scale * fdf->scale);
			ys = (fdf->twist[r][c].y * (fdf->size / (fdf->row + 1)) / 2) *
				(fdf->scale * fdf->scale);
			fdf->twist[r][c].x = xs + fdf->x_it + (fdf->size / 4);
			fdf->twist[r][c].y = ys + fdf->y_it + (fdf->size / 4);
			fdf->twist[r][c].z = fdf->twist[r][c].z * (fdf->size / 100);
		}
	}
}

void	apply_to(t_xyz *fdf, double iter, char check)
{
	int r;
	int c;

	r = -1;
	if (check == 'y')
		fdf->y_it += iter;
	if (check == 'x')
		fdf->x_it += iter;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			if (check == 'y')
				fdf->twist[r][c].y += iter;
			if (check == 'x')
				fdf->twist[r][c].x += iter;
		}
	}
}
