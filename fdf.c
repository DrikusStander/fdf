/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:21:17 by hstander          #+#    #+#             */
/*   Updated: 2017/06/28 16:50:10 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_points points;
	int fd;
	int color; 
	int color1;
	color1 = 0x000000ff;
	color = 0x0000ff00;
	
	char *line;
	char **arr;
 	int i;
	int j;
	int k;
	i = 1;
	j = 0;
	k = 0;
	fd = 0;
	if (ac != 1)
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 1600, 1600, "new window");

		fd = open(av[1], O_RDONLY);
		arr = NULL;
		points.prev = NULL;
		while (get_next_line(fd, &line))
		{
			arr = ft_strsplit(line, ' ');
			while(arr[i])
			{
				points.x1 = ((i-1) * 20) +100;
				points.y1 = (j * 20) + 100;
				points.z1 = (atoi(arr[i - 1]) * 20) + 100;
				
				points.x2 = (i * 20) + 100; 
				points.y2 = (j * 20) + 100;
				points.z2 = (atoi(arr[i]) * 20) + 100;
				toiso(&points);
				put_line(&points, &mlx, color + 100);
				if (points.prev != NULL)
				{
					while (points.prev[k])
					{
						points.x1 = (((k) * 20) + 100);
						points.y1 = ((j - 1) * 20) + 100;
						points.z1 = (atoi(points.prev[k]) * 20) + 100;
						
						points.x2 = ((k) * 20) + 100;
						points.y2 = (j * 20) + 100;
						points.z2 = (atoi(arr[k]) * 20) + 100;
						toiso(&points);
						put_line(&points, &mlx, color + 100);
						k++;
					}
		//			free(points.prev);
				}
			printf("i = %d\n", i);
			printf("k = %d\n", k);
			i++;
			}
			j++;
			k = 0;
			i = 1;
			free(arr);
			points.prev = ft_strsplit(line, ' ');
		}
		mlx_key_hook(mlx.win, key_hook, 0);
		mlx_loop(mlx.mlx);
	}
	close(fd);
	return (0);
}
