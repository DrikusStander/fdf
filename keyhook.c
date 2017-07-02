/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:56:25 by hstander          #+#    #+#             */
/*   Updated: 2017/07/02 14:12:34 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 121)
		lower_z(param);
	if (keycode == 116)
		raise_z(param);
	if (keycode == 124)
	{
		param->view += 0.5;
		readmap(param->file, param);
	}
	if (keycode == 123)
	{
		param->view -= 0.5;
		readmap(param->file, param);
	}
	if (keycode == 69)
		zoom_in(param);
	if (keycode == 78)
		zoom_out(param);
	return (0);
}

void	zoom_in(t_mlx *param)
{
	param->zoom += 0.5;
	readmap(param->file, param);
}

void	zoom_out(t_mlx *param)
{
	param->zoom -= 0.5;
	readmap(param->file, param);
}

void	raise_z(t_mlx *param)
{
	param->var_z += 0.5;
	readmap(param->file, param);
}

void	lower_z(t_mlx *param)
{
	param->var_z -= 0.5;
	readmap(param->file, param);
}
