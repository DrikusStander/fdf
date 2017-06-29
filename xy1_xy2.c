/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy1_xy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:50:01 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 14:50:08 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xy1_xy2(t_cord *cord, t_mlx *mlx, int color)
{
	int i;

	i = 1;
	while (i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
		cord->x += cord->dx;
		cord->y += cord->dy;
		i++;
	}
}

void	xy2_xy1(t_cord *cord, t_mlx *mlx, int color)
{
	int i;

	i = 1;
	while (i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
		cord->x -= cord->dx;
		cord->y -= cord->dy;
		i++;
	}
}

void	x1y2_x2y1(t_cord *cord, t_mlx *mlx, int color)
{
	int i;

	i = 1;
	while (i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
		cord->x += cord->dx;
		cord->y -= cord->dy;
		i++;
	}
}

void	x2y1_x1y2(t_cord *cord, t_mlx *mlx, int color)
{
	int	i;

	i = 1;
	while (i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, color);
		cord->x -= cord->dx;
		cord->y += cord->dy;
		i++;
	}
}
