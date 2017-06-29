/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 14:54:39 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 09:09:47 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_points *points, t_mlx *mlx, int color)
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
		xy1_xy2(&cord, mlx, color);
	if (points->x2 < points->x1 && points->y2 < points->y1)
		xy2_xy1(&cord, mlx, color);
	if (points->x1 < points->x2 && points->y1 > points->y2)
		x1y2_x2y1(&cord, mlx, color);
	if (points->x1 > points->x2 && points->y1 < points->y2)
		x2y1_x1y2(&cord, mlx, color);
	if (points->x1 == points->x2 && points->y1 != points->y2)
		xx_y1y2(&cord, mlx, points, color);
	if (points->x1 != points->x2 && points->y1 == points->y2)
		yy_x1x2(&cord, mlx, points, color);
}
