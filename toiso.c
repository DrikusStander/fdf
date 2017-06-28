/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toiso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 08:05:37 by hstander          #+#    #+#             */
/*   Updated: 2017/06/28 16:50:00 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    toiso(t_points *points)
{
	t_iso iso;

	iso.x1 = points->x1 - points->y1;
	iso.y1 = (points->x1 + points->y1) / 2;
	iso.x2 = points->x2 - points->y2;
	iso.y2 = (points->x2 + points->y2) / 2;

	points->x1 = (points->x1 - points->y1) + 400;
	points->y1 = (points->x1 +  (points->y1 - points->z1)) / 2;
	points->x2 = (points->x2 - points->y2) + 400;
	points->y2 = (points->x2 + (points->y2 - points->z2)) / 2;
}
