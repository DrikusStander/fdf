/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:56:25 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 17:02:17 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_mlx *param)
{
	//(void)param;
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 121)
	{
		param->var_z -= 0.5;
		readmap(param->file, param);

	}
	if (keycode == 116)
	{
		param->var_z += 0.5;
		readmap(param->file, param);
	}
	if (keycode == 69)
	{
		param->zoom += 0.5;
		readmap(param->file, param);
	}
	if (keycode == 78)
	{
		param->zoom -= 0.5;
		readmap(param->file, param);
	}
	return (0);
}
