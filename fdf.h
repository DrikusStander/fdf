/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:36:49 by hstander          #+#    #+#             */
/*   Updated: 2017/06/26 15:21:48 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_cord
{
	float	dx;
	float	dy;
	float	step;
	float	x;
	float	y;

} 				t_cord;

typedef	struct	s_mlx
{
	void *mlx;
	void *win;
}	t_mlx;

typedef struct	s_points
{
	int	x1;
	int y1;
	int	x2;
	int y2;
}				t_points;
