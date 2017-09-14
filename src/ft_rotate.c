/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:15:04 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:36:13 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		ft_new_trace(t_ws *prm)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < prm->nb_p - 1)
	{
		if ((i + 1) % prm->s_col != 0)
		{
			line.x = prm->mpt[i].x;
			line.y = prm->mpt[i].y;
			line.dx = prm->mpt[i + 1].x - line.x;
			line.dy = prm->mpt[i + 1].y - line.y;
			ft_line_to_img(prm, &line, prm->mpt[i].z);
		}
		if (i + prm->s_col < prm->nb_p)
		{
			line.x = prm->mpt[i].x;
			line.y = prm->mpt[i].y;
			line.dx = (prm->mpt[i + prm->s_col].x - line.x);
			line.dy = (prm->mpt[i + prm->s_col].y - line.y);
			ft_line_to_img(prm, &line, prm->mpt[i].z);
		}
		i++;
	}
}

static int	c_z(int z1, int z2)
{
	if (z1 > 0)
		return (z1);
	else if (z2 > 0)
		return (z2);
	return (0);
}

void		ft_iso_view(t_ws *prm)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < prm->nb_p)
	{
		if ((i + 1) % prm->s_col != 0)
		{
			line.x = prm->mpt[i].x;
			line.y = prm->mpt[i].y;
			line.dx = prm->mpt[i + 1].x - prm->mpt[i].x;
			line.dy = prm->mpt[i + 1].y - prm->mpt[i].y;
			ft_line_to_img(prm, &line, c_z(prm->mpt[i].z, prm->mpt[i + 1].z));
		}
		if (i + prm->s_col < prm->nb_p)
		{
			line.x = prm->mpt[i].x;
			line.y = prm->mpt[i].y;
			line.dx = prm->mpt[i + prm->s_col].x - (prm->mpt[i].x);
			line.dy = prm->mpt[i + prm->s_col].y - prm->mpt[i].y;
			ft_line_to_img(prm, &line,
				c_z(prm->mpt[i].z, prm->mpt[i + prm->s_col].z));
		}
		i++;
	}
}
