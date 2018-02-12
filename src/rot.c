/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:55:37 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/07 16:58:52 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	x_rot(t_xyz *fdf, double rad, int r, int c)
{
	double z1;
	double r1;

	rad *= (M_PI / 180);
	z1 = fdf->twist[r][c].z;
	r1 = r - (fdf->row / 2);
	fdf->twist[r][c].y = ((r1 + 1) * cos(rad)) - ((z1 + 1) * sin(rad));
	fdf->twist[r][c].z = ((r1 + 1) * sin(rad)) + ((z1 + 1) * cos(rad));
	fdf->twist[r][c].y += (fdf->row / 2);
}

void	y_rot(t_xyz *fdf, double rad, int r, int c)
{
	double c1;
	double z1;

	rad *= (M_PI / 180);
	c1 = c - (fdf->col / 2);
	z1 = fdf->twist[r][c].z;
	fdf->twist[r][c].x = ((c1 + 1) * cos(rad)) + ((z1 + 1) * sin(rad));
	fdf->twist[r][c].z = (((c1 + 1) * -sin(rad)) + ((z1 + 1) * cos(rad)));
	fdf->twist[r][c].x += (fdf->col / 2);
}

void	z_rot(t_xyz *fdf, double rad, int r, int c)
{
	double c1;
	double r1;

	rad = rad * (M_PI / 180);
	r1 = r - (fdf->row / 2);
	c1 = c - (fdf->col / 2);
	fdf->twist[r][c].x = ((c1 + 1) * cos(rad)) - ((r1 + 1) * sin(rad));
	fdf->twist[r][c].y = ((r1 + 1) * sin(rad)) + ((r1 + 1) * cos(rad));
	fdf->twist[r][c].x += (fdf->col / 2);
	fdf->twist[r][c].y += (fdf->row / 2);
}

void	rot_suite(t_xyz *fdf)
{
	int r;
	int c;

	r = -1;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			fdf->twist[r][c].z = fdf->twist[r][c].crossz;
			y_rot(fdf, fdf->rot_y, r, c);
			z_rot(fdf, fdf->rot_z, r, c);
			x_rot(fdf, fdf->rot_x, r, c);
		}
	}
}
