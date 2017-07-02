/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 08:48:34 by hstander          #+#    #+#             */
/*   Updated: 2017/07/02 14:23:21 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_right(t_count *c, t_points *points, t_mlx *mlx)
{
	points->x1 = ((c->i - 1) * c->sc) + 100;
	points->y1 = (c->j * c->sc) + 100;
	points->z1 = (ft_atoi(points->arr[c->i - 1]) * c->sz) + 100;
	points->x2 = (c->i * c->sc) + 100;
	points->y2 = (c->j * c->sc) + 100;
	points->z2 = (ft_atoi(points->arr[c->i]) * c->sz) + 100;
	toiso(points, mlx);
	put_line(points, mlx, mlx->color);
}

void	draw_left(t_count *c, t_points *points, t_mlx *mlx)
{
	points->x1 = (((c->k) * c->sc) + 100);
	points->y1 = ((c->j - 1) * c->sc) + 100;
	points->z1 = (ft_atoi(points->prev[c->k]) * c->sz) + 100;
	points->x2 = ((c->k) * c->sc) + 100;
	points->y2 = (c->j * c->sc) + 100;
	points->z2 = (ft_atoi(points->arr[c->k]) * c->sz) + 100;
	toiso(points, mlx);
	put_line(points, mlx, mlx->color);
	c->k++;
}

void	drawloop(t_points *points, t_count *c, t_mlx *mlx)
{
	char	*line;

	while (get_next_line(c->fd, &line))
	{
		points->arr = ft_strsplit(line, ' ');
		while (points->arr[c->i])
		{
			draw_right(c, points, mlx);
			if (points->prev != NULL)
			{
				while (points->prev[c->k])
					draw_left(c, points, mlx);
			}
			c->i++;
		}
		c->j++;
		c->k = 0;
		c->i = 1;
		if (points->prev != NULL)
			free(points->prev);
		free(points->arr);
		points->prev = ft_strsplit(line, ' ');
	}
}

void	readmap(char *file, t_mlx *mlx)
{
	t_points	points;
	t_count		c;

	mlx_clear_window(mlx->mlx, mlx->win);
	ft_bzero(&c, sizeof(t_count));
	ft_bzero(&points, sizeof(t_points));
	c.i = 1;
	c.sc = 2;
	c.sc *= mlx->zoom;
	c.sz = c.sc * mlx->var_z;
	mlx->color = 0x0000ff00;
	c.fd = open(file, O_RDONLY);
	drawloop(&points, &c, mlx);
	close(c.fd);
}
