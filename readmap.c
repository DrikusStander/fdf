/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 08:48:34 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 09:26:27 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_right(t_count *c, t_points *points, t_mlx *mlx)
{
	points->x1 = ((c->i - 1) * 20) + 100;
	points->y1 = (c->j * 20) + 100;
	points->z1 = (ft_atoi(points->arr[c->i - 1]) * 20) + 100;
	points->x2 = (c->i * 20) + 100;
	points->y2 = (c->j * 20) + 100;
	points->z2 = (ft_atoi(points->arr[c->i]) * 20) + 100;
	toiso(points);
	put_line(points, mlx, mlx->color);
}

void	draw_left(t_count *c, t_points *points, t_mlx *mlx)
{
	points->x1 = (((c->k) * 20) + 100);
	points->y1 = ((c->j - 1) * 20) + 100;
	points->z1 = (ft_atoi(points->prev[c->k]) * 20) + 100;
	points->x2 = ((c->k) * 20) + 100;
	points->y2 = (c->j * 20) + 100;
	points->z2 = (ft_atoi(points->arr[c->k]) * 20) + 100;
	toiso(points);
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
			//free(points->prev);
			}
			c->i++;
		}
		c->j++;
		c->k = 0;
		c->i = 1;
		free(points->arr);
		points->prev = ft_strsplit(line, ' ');
	}
}

void	readmap(char *file, t_mlx *mlx)
{
	t_points	points;
	t_count		c;

	ft_bzero(&c, sizeof(t_count));
	c.i = 1;
	mlx->color = 0xffffff;
	c.fd = open(file, O_RDONLY);
	drawloop(&points, &c, mlx);
	close(c.fd);
}
