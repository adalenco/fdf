/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:50:32 by adalenco          #+#    #+#             */
/*   Updated: 2017/05/22 19:44:04 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "X.h"
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_point // points brut
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_fpoint
{
	float			x;
	float			y;
	float			z;
}					t_fpoint;

typedef struct		s_ws
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*img_ad;
	int				bpp;
	int				s_l;
	int				endian;
	int				winx;
	int				winy;
	float			z_scale;
	t_point			*point; // coordonnees brutes
	t_fpoint		*mpt;
	int				nb_p; //nb de points total
	int				s_col; // nombre colonnes
	int				s_line; // nombre lignes
	int				square_size; // espacement des points
	float			mod_x; // centrer les x
	float			mod_y; // centrer ta mere
	int				tr_x; // translations x
	int				tr_y; // transaltions powpowpow
	int				x_scale;
	int				y_scale;
}					t_ws;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				x;
	int				y;
}					t_line;

int			ft_read_parse(int fd, t_ws *prm);
void		ft_trace_line(t_ws *prm, int x0, int y0, int x1, int y1);
void		ft_pixel_to_image(t_ws *prm, int x, int y, int color);
void		ft_line_to_img(t_ws *prm, t_line *line, int z);
void		ft_trace_map(t_ws *prm);
void		ft_upper_view(t_ws *prm);
void		ft_iso_view(t_ws *prm);
int			ft_key_funct(int keycode, t_ws *prm);
void		ft_refresh_image(t_ws *prm);
void		ft_r_z(t_ws *prm, float angle);


#endif
