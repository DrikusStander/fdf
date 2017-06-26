/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:21:17 by hstander          #+#    #+#             */
/*   Updated: 2017/06/26 16:35:16 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

void	put_line(t_points *points, t_mlx *mlx)
{
	t_cord cord;

	cord.dx = abs(points->x2 - points->x1);
	cord.dy = abs(points->y2 - points->y1);
	if (cord.dx >= cord.dy)
		cord.step = cord.dx;
	else
		cord.step = cord.dy;
	cord.dx /= cord.step;
	cord.dy /= cord.step;
	cord.x = points->x1;
	cord.y = points->y1;
	if (points->x1 < points->x2 && points->y1 < points->y2)
		xy1_xy2(&cord, mlx);
	if (points->x2 < points->x1 && points->y2 < points->y1)
		xy2_xy1(&cord, mlx);
	if (points->x1 < points->x2 && points->y1 > points->y2)
		x1y2_x2y1(&cord, mlx);
	if (points->x1 > points->x2 && points->y1 < points->y2)
		x2y1_x1y2(&cord, mlx);
	if (points->x1 == points->x2 && points->y1 != points->y2)
		xx_y1y2(&cord, mlx, points);
	if (points->x1 != points->x2 && points->y1 == points->y2)
		yy_x1x2(&cord, mlx, points);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_points points;

	if (ac == 5)
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 500, 500, "new window");
		points.x1 = atoi(av[1]);
		points.y1 = atoi(av[2]);
		points.x2 = atoi(av[3]);
		points.y2 = atoi(av[4]);
		put_line(&points, &mlx);
		mlx_string_put(mlx.mlx, mlx.win, 0, 0, 0xff0000, "0");
		mlx_string_put(mlx.mlx, mlx.win, 470, 0, 0xff0000, "500");
		mlx_string_put(mlx.mlx, mlx.win, 0,  470, 0xff0000, "500");
		mlx_key_hook(mlx.win, key_hook, 0);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
