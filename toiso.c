/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toiso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 08:05:37 by hstander          #+#    #+#             */
/*   Updated: 2017/06/29 15:03:59 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	toiso(t_points *points)
{
	points->x1 = (points->x1 - points->y1) + 400;
	points->y1 = (points->x1 + (points->y1 - points->z1)) / 2;
	points->x2 = (points->x2 - points->y2) + 400;
	points->y2 = (points->x2 + (points->y2 - points->z2)) / 2;
}
