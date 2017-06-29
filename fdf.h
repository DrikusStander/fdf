/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:36:49 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 09:35:25 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_cord
{
	float		dx;
	float		dy;
	float		step;
	float		x;
	float		y;

}				t_cord;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			color;
}				t_mlx;

typedef struct	s_points
{
	int			x1;
	int			y1;
	int			z1;
	int			x2;
	int			y2;
	int			z2;
	char		**prev;
	char		**arr;

}				t_points;

typedef struct	s_count
{
	int			i;
	int			j;
	int			k;
	int			fd;
}				t_count;

typedef struct	s_iso
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
}				t_iso;

void			xy1_xy2(t_cord *cord, t_mlx *mlx, int color);
void			xy2_xy1(t_cord *cord, t_mlx *mlx, int color);
void			x1y2_x2y1(t_cord *cord, t_mlx *mlx, int color);
void			x2y1_x1y2(t_cord *cord, t_mlx *mlx, int color);
void			xx_y1y2(t_cord *cord, t_mlx *mlx, t_points *points, int color);
void			yy_x1x2(t_cord *cord, t_mlx *mlx, t_points *points, int color);
void			put_line(t_points *points, t_mlx *mlx, int color);
int				key_hook(int keycode, void *param);
void			toiso(t_points *points);
void			readmap(char *file, t_mlx *mlx);
void			drawloop(t_points *points, t_count *c, t_mlx *mlx);
void			draw_left(t_count *c, t_points *points, t_mlx *mlx);
void			draw_right(t_count *c, t_points *points, t_mlx *mlx);

#endif
