/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toiso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 08:05:37 by hstander          #+#    #+#             */
/*   Updated: 2017/07/02 14:14:55 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	toiso(t_points *points, t_mlx *mlx)
{
	int x1;
	int x2;
	int y1;
	int y2;

	x1 = points->x1;
	x2 = points->x2;
	y1 = points->y1;
	y2 = points->y2;
	points->x1 = ((x1 - y1) + (400 / mlx->view)) * mlx->view;
	points->y1 = ((x1 + (y1 - points->z1)) / 2) + 200;
	points->x2 = ((x2 - y2) + (400 / mlx->view)) * mlx->view;
	points->y2 = ((x2 + (y2 - points->z2)) / 2) + 200;
}
