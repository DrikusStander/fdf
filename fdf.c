/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:21:17 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 17:02:26 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 1)
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "new window");
		mlx.var_z = 1;
		mlx.zoom = 1;
		mlx.file = av[1];
		readmap(av[1], &mlx);
		mlx_key_hook(mlx.win, key_hook, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
