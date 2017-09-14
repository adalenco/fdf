/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:38:02 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:30:31 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_refresh_image(t_ws *param)
{
	mlx_destroy_image(param->mlx, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx, param->winx, param->winy);
	param->img_ad = mlx_get_data_addr(param->img_ptr, &param->bpp, \
			&param->s_l, &param->endian);
}
