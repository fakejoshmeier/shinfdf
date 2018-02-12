/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:55:22 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/10 14:57:49 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				colorize(t_xyz *f, int x, int y, double u)
{
	int		pos;

	if ((x >= 0 && y >= 0) && x < W_WIDTH && y < W_HEIGHT)
	{
		pos = x + (y * f->s_line / 4);
		f->canvas[pos] = blend(f->a.iro, f->b.iro, 'r') + u;
		f->canvas[pos + 1] = blend(f->a.iro, f->b.iro, 'g') + u;
		f->canvas[pos + 2] = blend(f->a.iro, f->b.iro, 'b') + u;
		f->canvas[pos + 3] = 0x7F + u;
	}
}

void				draw_line(t_xyz *fdf)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	uvector;

	x = fdf->c0;
	y = fdf->r0;
	dx = fdf->c1 - fdf->c0;
	dy = fdf->r1 - fdf->r1;
	uvector = sqrt((pow(dx, 2)) + (pow(dy, 2)));
	dx /= uvector;
	dy /= uvector;
	while (uvector > 0)
	{
		colorize(fdf, x, y, uvector);
		x += dx;
		y += dy;
		uvector -= 1;
	}
}

void				draw(t_xyz *fdf, int r, int c, char check)
{
	int		xt;
	int		yt;
	int		r4;
	int		c4;

	r4 = check == 'r' ? r + 1 : r;
	c4 = check == 'c' ? c + 1 : c;
	fdf->a = fdf->twist[r][c];
	fdf->b = fdf->twist[r4][c4];
	xt = c - fdf->col / 2;
	yt = r - fdf->row / 2;
	fdf->c0 = fdf->rot_x * (xt - yt) * fdf->zoom;
	fdf->r0 = fdf->rot_y * (xt + yt) * fdf->zoom;
	fdf->r0 -= fdf->bumps[r][c] * fdf->z_value;
	fdf->c1 = check == 'r' ? fdf->rot_x * ((xt + 1) - yt) * fdf->zoom :
		fdf->rot_x * ((xt - (yt + 1)) * fdf->zoom);
	fdf->r1 = check == 'r' ? fdf->rot_y * ((xt + 1) + yt) * fdf->zoom :
		fdf->rot_y * ((xt + (yt + 1)) * fdf->zoom);
	fdf->r1 -= fdf->bumps[r4][c4] * fdf->z_value;
	fdf->c0 += (W_WIDTH / 2) + fdf->coordinate_y;
	fdf->c1 += (W_WIDTH / 2) + fdf->coordinate_y;
	fdf->r0 += (W_HEIGHT / 2) + fdf->coordinate_x;
	fdf->r1 += (W_HEIGHT / 2) + fdf->coordinate_x;
	draw_line(fdf);
}

int				first_draw(t_xyz *fdf)
{
	int		r;
	int		c;

	fdf->img = mlx_new_image(fdf->mlx, W_WIDTH, W_HEIGHT);
	fdf->canvas = mlx_get_data_addr(fdf->img, &fdf->bits, &fdf->s_line,
		&fdf->endian);
	r = -1;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			fdf->r0 = r;
			fdf->c0 = c;
			c + 1 < fdf->col ? draw(fdf, r, c, 'c') : 0;
			r + 1 < fdf->row ? draw(fdf, r, c, 'r') : 0;
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);
	return (0);
}
