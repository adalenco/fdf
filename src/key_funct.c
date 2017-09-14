/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:12:51 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:35:13 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_key_funct(int keycode, t_ws *prm)
{
	ft_refresh_image(prm);
	if (keycode == 53 || keycode == 12)
	{
		(void)prm;
		exit(0);
	}
	if (keycode == 2)
		prm->x_scale += 10;
	if (keycode == 0)
		prm->x_scale -= 10;
	if (keycode == 13)
		prm->y_scale -= 10;
	if (keycode == 1)
		prm->y_scale += 10;
	if (keycode == 116)
		prm->z_scale += 0.01;
	if (keycode == 121)
		prm->z_scale -= 0.01;
	if (keycode == 78 && prm->square_size > 2)
		prm->square_size -= 2;
	if (keycode == 69)
		prm->square_size += 2;
	ft_trace_map(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img_ptr, 0, 0);
	return (0);
}
