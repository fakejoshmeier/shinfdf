/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:55:21 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/10 14:52:54 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		hooks(int keycode, t_xyz *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_W)
		fdf->coordinate_x -= 1;
	else if (keycode == KEY_ANSI_A)
		fdf->coordinate_y -= 1;
	else if (keycode == KEY_ANSI_S)
		fdf->coordinate_x += 1;
	else if (keycode == KEY_ANSI_D)
		fdf->coordinate_y += 1;
	else if (keycode == KEY_ANSI_B)
		fdf->zoom += 1;
	else if ((keycode == KEY_ANSI_N) && (fdf->zoom > MAX_ZOOM))
		fdf->zoom -= 1;
	else if ((keycode == KEY_ANSI_J) && (fdf->z_value < MAX_X))
		fdf->z_value += 0.25;
	else if ((keycode == KEY_ANSI_K) && (fdf->z_value > -MAX_X))
		fdf->z_value -= 0.25;
	return (0);
}

void	first_things_first(t_xyz *fdf)
{
	fdf->coordinate_x = 0;
	fdf->coordinate_y = 0;
	fdf->z_value = 1.00;
	fdf->rot_x = cos(M_PI / 3);
	fdf->rot_y = fdf->rot_x * sin(M_PI / 6);
	fdf->zoom = ceil((fdf->col > fdf->row))
		? (W_WIDTH / fdf->col) + MAGIC_ZOOM
		: (W_HEIGHT / fdf->row) + MAGIC_ZOOM;
	fdf->iso = 1;
}

void	error(char *str)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	exit(0);
}

int		main(int ac, char *av[])
{
	t_xyz	fdf;

	ac == 2 ? 0 : error("Usage ./fdf [TEST.fdf]\n");
	ft_strstr(av[1], ".fdf") ? 0 : error("Invalid filetype\n");
	ft_bzero(&fdf, sizeof(t_xyz));
	parse_suite(&fdf, av[1]);
	first_things_first(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, W_WIDTH, W_HEIGHT, av[1]);
	mlx_hook(fdf.win, 2, 3, hooks, &fdf);
	mlx_loop_hook(fdf.mlx, first_draw, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
