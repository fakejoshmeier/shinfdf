/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:47:51 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/08 23:46:19 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rot_n_scale(t_xyz *fdf)
{
	rot_suite(fdf);
	scale(fdf);
}

void	apply_n_draw(t_xyz *fdf, int iter, char check)
{
	apply_to(fdf, iter, check);
	first_draw(fdf);
}

/*
** 13 - W pressed
**  0 - A pressed
**  1 - S pressed
**  2 - D pressed
** 92) //9/right pressed
** 89) //7/left pressed
*/

int		pan_hook(int keycode, t_xyz *fdf)
{
	if (keycode == 92)
	{
		rot_suite(fdf);
		scale(fdf);
		fdf->rot_y += 1;
		first_draw(fdf);
	}
	if (keycode == 89)
	{
		rot_suite(fdf);
		scale(fdf);
		fdf->rot_y -= 1;
		first_draw(fdf);
	}
	if (keycode == 13)
		apply_n_draw(fdf, -10, 'y');
	if (keycode == 0)
		apply_n_draw(fdf, -10, 'x');
	if (keycode == 1)
		apply_n_draw(fdf, 10, 'y');
	if (keycode == 2)
		apply_n_draw(fdf, 10, 'x');
	return (0);
}

/*
** 126 up pressed
** 125 down pressed
** 124 right pressed
** 123 left pressed
*/

int		rot_hook(int keycode, t_xyz *fdf)
{
	if (keycode == 126)
	{
		rot_n_scale(fdf);
		fdf->rot_x += 1;
		first_draw(fdf);
	}
	if (keycode == 125)
	{
		rot_n_scale(fdf);
		fdf->rot_x -= 1;
		first_draw(fdf);
	}
	if (keycode == 124)
	{
		rot_n_scale(fdf);
		fdf->rot_z += 1;
		first_draw(fdf);
	}
	if (keycode == 123)
	{
		rot_n_scale(fdf);
		fdf->rot_z -= 1;
		first_draw(fdf);
	}
	return (0);
}

/*
** 69 + pressed
** 78 - pressed
*/

int		zoom_hook(int keycode, t_xyz *fdf)
{
	if (keycode == 53)
		exit(1);
	pan_hook(keycode, fdf);
	rot_hook(keycode, fdf);
	if (keycode == 69)
	{
		fdf->scale += .01;
		rot_suite(fdf);
		scale(fdf);
		first_draw(fdf);
	}
	if (keycode == 78)
	{
		fdf->scale -= .01;
		rot_suite(fdf);
		scale(fdf);
		first_draw(fdf);
	}
	return (0);
}
