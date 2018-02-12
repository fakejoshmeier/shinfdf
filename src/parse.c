/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:59:42 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/10 14:37:09 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		garbage_check(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]) || ft_isspace(str[i]))
			return (1);
	}
	return (0);
}

void	twister(t_xyz *f)
{
	int		r;
	int		c;

	r = -1;
	f->twist = ft_memalloc(sizeof(t_jig *) * f->row);
	while (++r < f->row)
	{
		f->twist[r] = ft_memalloc(sizeof(t_jig) * f->col);
		ft_bzero(f->twist[r], f->col);
		c = -1;
		while (++c < f->col)
		{
			f->twist[r][c].x = r;
			f->twist[r][c].y = c;
			f->twist[r][c].z = f->bumps[r][c];
			if (f->bumps[r][c] == 0)
				f->twist[r][c].iro = 0xFFFFFF;
			else
				f->twist[r][c].iro = f->bumps[r][c] > 0 ? 0x66023c : 0x02662c;
			f->twist[r][c].crossz = f->twist[r][c].z;
		}
	}
}

void	cannibalize(t_xyz *fdf, int fd)
{
	char	**tmp;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (get_next_line(fd, &str))
	{
		tmp = ft_strsplit(str, ' ');
		while (++i < fdf->row)
		{
			fdf->bumps[i] = ft_memalloc(sizeof(int) * fdf->col);
			while (++j < fdf->col)
			{
				garbage_check(tmp[j]) == 0 ? 0 : error("Invalid characters\n");
				fdf->bumps[i][j] = ft_atoi(tmp[j]);
			}
			j = -1;
			break ;
		}
		free(tmp);
	}
	free(str);
	close(fd);
}

void	validate(t_xyz *fdf, int fd)
{
	char	*str;
	char	**grid;
	int		i;

	while (get_next_line(fd, &str))
	{
		i = -1;
		grid = ft_strsplit(str, ' ');
		while (grid[++i])
			;
		if (fdf->row == 0)
		{
			fdf->col = i;
			fdf->row = 1;
		}
		else
		{
			fdf->col == i ? 0 : error("Invalid fug\n");
			++fdf->row;
		}
		free(grid);
	}
	fdf->bumps = ft_memalloc(sizeof(int *) * fdf->row);
	free(str);
	close(fd);
}

void	parse_suite(t_xyz *fdf, char *av)
{
	int		fd;

	(fd = open(av, O_RDONLY)) < 0 ? error("Unable to open file\n") : 0;
	validate(fdf, fd);
	fd = open(av, O_RDONLY);
	cannibalize(fdf, fd);
	twister(fdf);
}
