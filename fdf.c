/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:21:17 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 08:55:27 by hstander         ###   ########.fr       */
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
		mlx.win = mlx_new_window(mlx.mlx, 1600, 1600, "new window");
		readmap(av[1], &mlx);
		mlx_key_hook(mlx.win, key_hook, 0);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
