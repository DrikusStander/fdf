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

int		key_hook(int keycode, void *param)
{
	(void)param;
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 121)
		parm->varz -= 0.5;
	return (0);
}
