/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:36:49 by hstander          #+#    #+#             */
/*   Updated: 2017/06/26 16:35:06 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

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

void	xy1_xy2(t_cord *cord, t_mlx *mlx);
void	xy2_xy1(t_cord *cord, t_mlx *mlx);
void	x1y2_x2y1(t_cord *cord, t_mlx *mlx);
void	x2y1_x1y2(t_cord *cord, t_mlx *mlx);
void	xx_y1y2(t_cord *cord, t_mlx *mlx, t_points *points);
void	yy_x1x2(t_cord *cord, t_mlx *mlx, t_points *points);
void	put_line(t_points *points, t_mlx *mlx);
int     key_hook(int keycode, void *param);

#endif
