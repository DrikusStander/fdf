/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:21:17 by hstander          #+#    #+#             */
/*   Updated: 2017/06/26 15:21:44 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

void	xy1_xy2(t_cord *cord, t_mlx *mlx)
{
	int i;

	i = 1;
	while(i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
		cord->x += cord->dx;
		cord->y += cord->dy;
		i++;
	}
}

void	xy2_xy1(t_cord *cord, t_mlx *mlx)
{
	int i;

	i = 1;
	while(i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
		cord->x -= cord->dx;
		cord->y -= cord->dy;
		i++;
	}
}

void	x1y2_x2y1(t_cord *cord, t_mlx *mlx)
{
	int i;

	i = 1;
	while(i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
		cord->x += cord->dx;
		cord->y -= cord->dy;
		i++;
	}
}

void	x2y1_x1y2(t_cord *cord, t_mlx *mlx)
{
	int	i;

	i = 1;
	while(i <= cord->step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
		cord->x -= cord->dx;
		cord->y += cord->dy;
		i++;
	}
}

void	xx_y1y2(t_cord *cord, t_mlx *mlx, t_points *points)
{
	int i;

	i = 1;
	if (points->y1 < points->y2)
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
			cord->y += cord->dy;
			i++;
		}
	}
	else
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
			cord->y -= cord->dy;
			i++;
		}
	}
}

void	yy_x1x2(t_cord *cord, t_mlx *mlx, t_points *points)
{
	int i;

	i = 1;
	if (points->x1 < points->x2)
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
			cord->x += cord->dx;
			i++;
		}
	}
	else
	{
		while(i <= cord->step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, cord->x, cord->y, 0x00ff0000);
			cord->x -= cord->dx;
			i++;
		}
	}
}

void	put_line(t_points *points, t_mlx *mlx)
{
	t_cord cord;
	int i;
	float x;
	float y;

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
	i = 1;
	if (points->x1 < points->x2 && points->y1 < points->y2)
	{
		xy1_xy2(&cord, mlx);
		/*while(i <= cord.step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
			cord.x += cord.dx;
			cord.y += cord.dy;
			i++;
		}*/
	}
	if (points->x2 < points->x1 && points->y2 < points->y1)
	{
		xy2_xy1(&cord, mlx);
	/*	while(i <= cord.step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
			x = x - cord.dx;
			y = y - cord.dy;
			i++;
		}*/
	}
	if (points->x1 < points->x2 && points->y1 > points->y2)
	{
		x1y2_x2y1(&cord, mlx);
	/*	while(i <= cord.step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
			x = x + cord.dx;
			y = y - cord.dy;
			i++;
		}*/
	}
	if (points->x1 > points->x2 && points->y1 < points->y2)
	{
		x2y1_x1y2(&cord, mlx);
		/*while(i <= cord.step)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
			x = x - cord.dx;
			y = y + cord.dy;
			i++;
		}*/
	}
	if (points->x1 == points->x2 && points->y1 != points->y2)
	{
		xx_y1y2(&cord, mlx, points);
	/*	if (points->y1 < points->y2)
		{
			while(i <= cord.step)
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
				y = y + cord.dy;
				i++;
			}
		}
		else
		{
			while(i <= cord.step)
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
				y = y - cord.dy;
				i++;
			}
		}*/
	}
	if (points->x1 != points->x2 && points->y1 == points->y2)
	{
		yy_x1x2(&cord, mlx, points);
		/*if (points->x1 < points->x2)
		{
			while(i <= cord.step)
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
				x = x + cord.dx;
				i++;
			}
		}
		else
		{
			while(i <= cord.step)
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x00ff0000);
				x = x - cord.dx;
				i++;
			}
		}*/
	}
}


int		key_hook(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	return (0);
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
