/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:22:42 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:45:46 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_real_coord(t_ws *prm)
{
	int		i;
	float	modx;
	float	mody;

	modx = 1;
	mody = 15;
	i = 0;
	prm->mod_x = ((float)prm->winx / 2) - ((float)prm->s_col / 2);
	prm->mod_y = ((float)prm->winy / 2) - ((float)prm->s_line / 2);
	while (i < prm->nb_p)
	{
		prm->mpt[i].x = ((float)prm->point[i].x + (modx * (i / prm->s_col) - 1)) * (float)prm->square_size +
			prm->mod_x + (float)prm->x_scale ;
		prm->mpt[i].y = ((float)prm->point[i].y + ((float)prm->point[i].z
					* (0 - (float)prm->z_scale))) * (float)prm->square_size +
			(float)prm->y_scale + prm->mod_y;
		prm->mpt[i].z = (float)prm->point[i].z;
		i++;
	}
}

void		ft_trace_map(t_ws *prm)
{
	if (!(prm->mpt = (t_fpoint *)malloc(sizeof(t_point) * prm->nb_p)))
		exit(0);
	ft_real_coord(prm);
	ft_iso_view(prm);
}
