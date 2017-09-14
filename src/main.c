/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:55:13 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:37:04 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void		ft_mlx_set(t_ws *prm, int x, int y)
{
	prm->winx = x;
	prm->winy = y;
	prm->square_size = 20;
	prm->mlx = mlx_init();
	prm->win = mlx_new_window(prm->mlx, prm->winx, prm->winy, "This is FDF");
	prm->img_ptr = mlx_new_image(prm->mlx, prm->winx, prm->winy);
	prm->img_ad = mlx_get_data_addr(prm->img_ptr, &prm->bpp, &prm->s_l, \
			&prm->endian);
	prm->nb_p = 0;
}

int			ft_file_error(int type)
{
	if (type == 0)
		ft_putendl("usage : ./fdf <map.fdf>");
	else if (type == 1)
		ft_putendl("invalid file");
	else if (type == 2)
		ft_putendl("invalid map");
	return (-1);
}

int			main(int ac, char **av)
{
	int		fd;
	t_ws	prm;

	ft_mlx_set(&prm, 1920, 1080);
	if (ac != 2)
		return (ft_file_error(0));
	if ((fd = open(av[1], O_RDONLY)) < 1)
		return (ft_file_error(1));
	if ((ft_read_parse(fd, &prm) == -1))
		return (ft_file_error(2));
	prm.s_line = prm.nb_p / prm.s_col;
	prm.z_scale = 0.1;
	prm.x_scale = 0;
	prm.y_scale = 0;
	ft_trace_map(&prm);
	mlx_put_image_to_window(prm.mlx, prm.win, prm.img_ptr, 0, 0);
	mlx_hook(prm.win, KeyPress, KeyPressMask, ft_key_funct, &prm);
	mlx_loop(prm.mlx);
	return (0);
}
