/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_y1y2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:51:07 by hstander          #+#    #+#             */
/*   Updated: 2017/06/28 09:53:31 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xx_y1y2(t_cord *cord, t_mlx *mlx, t_points *points, int color)
{
	int i;

	i = 1;
	if (points->y1 < points->y2)
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
			cord->y += cord->dy;
			i++;
		}
	}
	else
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
			cord->y -= cord->dy;
			i++;
		}
	}
}

void	yy_x1x2(t_cord *cord, t_mlx *mlx, t_points *points, int color)
{
	int i;

	i = 1;
	if (points->x1 < points->x2)
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
			cord->x += cord->dx;
			i++;
		}
	}
	else
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
			cord->x -= cord->dx;
			i++;
		}
	}
}
