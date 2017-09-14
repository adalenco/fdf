/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:31:38 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:38:09 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

void			ft_pixel_to_image(t_ws *prm, int x, int y, int color)
{
	int			pixel_pos;

	pixel_pos = 4 * x + y * prm->s_l;
	prm->img_ad[pixel_pos] = (color & 0x000000FF);
	prm->img_ad[pixel_pos + 1] = (color & 0x0000FF00) >> 8;
	prm->img_ad[pixel_pos + 2] = (color & 0x00FF0000) >> 16;
	prm->img_ad[pixel_pos + 3] = prm->endian;
}

static void		ft_h_line(t_ws *prm, t_line *line, int color, int z)
{
	int			cumul;
	int			i;
	int			abs_dy;
	int			abs_dx;

	abs_dx = ft_abs(line->dx);
	abs_dy = ft_abs(line->dy);
	i = 1;
	cumul = abs_dx / 2;
	while (i <= abs_dx)
	{
		if (z != 0)
			color -= 1;
		line->x += (line->dx > 0) ? 1 : -1;
		cumul += abs_dy;
		if (cumul >= abs_dx)
		{
			cumul -= abs_dx;
			line->y += (line->dy > 0) ? 1 : -1;
		}
		if (line->x < prm->winx && line->x > 0
				&& line->y > 0 && line->y < prm->winy)
			ft_pixel_to_image(prm, line->x, line->y, color);
		i++;
	}
}

static void		ft_v_line(t_ws *prm, t_line *line, int color, int z)
{
	int			cumul;
	int			i;
	int			abs_dy;
	int			abs_dx;

	abs_dx = ft_abs(line->dx);
	abs_dy = ft_abs(line->dy);
	i = 1;
	cumul = abs_dy / 2;
	while (i <= abs_dy)
	{
		if (z != 0)
			color -= 1;
		line->y += (line->dy > 0) ? 1 : -1;
		cumul += abs_dx;
		if (cumul >= abs_dy)
		{
			cumul -= abs_dy;
			line->x += (line->dx > 0) ? 1 : -1;
		}
		if (line->x < prm->winx && line->x > 0
				&& line->y > 0 && line->y < prm->winy)
			ft_pixel_to_image(prm, line->x, line->y, color);
		i++;
	}
}

void			ft_line_to_img(t_ws *prm, t_line *line, int z)
{
	int			color;

	color = 0x00FFFFFF;
	if (z >= 10)
		color = 0x0000FFFF;
	if (line->x < prm->winx && line->x > 0
			&& line->y > 0 && line->y < prm->winy)
		ft_pixel_to_image(prm, line->x, line->y, color);
	if (ft_abs(line->dx) > ft_abs(line->dy))
		ft_h_line(prm, line, color, z);
	else
		ft_v_line(prm, line, color, z);
}
