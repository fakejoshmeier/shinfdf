/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:54:50 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/10 14:41:14 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <ft_printf.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <keys.h>
# define W_HEIGHT 720
# define W_WIDTH 1280
# define MAX_X 10
# define MAX_ZOOM 5
# define MAGIC_ZOOM 2

typedef struct	s_jig
{
	unsigned int	iro;
	double			x;
	double			y;
	double			z;
	double			crossz;
}					t_jig;

typedef struct		s_xyz
{
	int				col;
	int				row;
	int				**bumps;
	t_jig			**twist;
	double			rot_x;
	double			rot_y;
	double			z_value;
	double			zoom;
	int				iso;
	int				coordinate_x;
	int				coordinate_y;
	double			x_it;
	double			y_it;
	void			*mlx;
	void			*win;
	void			*img;
	char			*canvas;
	int				bits;
	int				endian;
	int				s_line;
	int				r0;
	int				c0;
	int				r1;
	int				c1;
	t_jig			a;
	t_jig			b;
}					t_xyz;

void			error(char *str);

void			parse_suite(t_xyz *fdf, char *av);
void			validate(t_xyz *fdf, int fd);
void			cannibalize(t_xyz *fdf, int fd);
void			twister(t_xyz *fdf);
int				garbage_check(char *str);

int				first_draw(t_xyz *fdf);
void			draw(t_xyz *fdf, int r, int c, char check);
void			draw_line(t_xyz *fdf);
void			colorize(t_xyz *fdf, int x, int y, double u);


//t_bres			bresenham(t_jig a, t_jig b);
//void			fillin(t_bres *ret);
//int				find_pos(t_xyz *fdf, int x, int y);
unsigned int	blend(unsigned int c1, unsigned int c2, char rgb);
#endif
