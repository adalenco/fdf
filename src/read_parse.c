/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:28:52 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:39:05 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int			ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		ft_free_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

t_point		*ft_realloc_t_point(t_ws *prm, int size)
{
	t_point	*cpy;
	int		i;

	i = 0;
	if (size == 0)
		return (NULL);
	if (prm->point == NULL)
	{
		if (!(cpy = (t_point *)ft_memalloc(sizeof(t_point) * size)))
			return (NULL);
		return (cpy);
	}
	if (!(cpy = (t_point *)ft_memalloc(sizeof(t_point) * (size + prm->nb_p))))
		return (NULL);
	while (i < prm->nb_p)
	{
		cpy[i].x = prm->point[i].x;
		cpy[i].y = prm->point[i].y;
		cpy[i].z = prm->point[i].z;
		ft_memdel((void **)prm->point);
		i++;
	}
	return (cpy);
}

int			ft_parse(t_ws *prm, char **splited, int y)
{
	int		i;

	i = 0;
	if (prm->nb_p == 0)
		prm->s_col = ft_tablen(splited);
	else if (ft_tablen(splited) != prm->s_col)
		return (-1);
	prm->point = ft_realloc_t_point(prm, ft_tablen(splited));
	while (splited[i])
	{
		prm->point[i + prm->nb_p].x = i;
		prm->point[i + prm->nb_p].y = y;
		prm->point[i + prm->nb_p].z = ft_atoi(splited[i]);
		i++;
	}
	prm->nb_p += ft_tablen(splited);
	return (i);
}

int			ft_read_parse(int fd, t_ws *prm)
{
	char	*buf;
	int		i;
	int		y;
	char	**splited;

	y = 0;
	while (get_next_line(fd, &buf) > 0)
	{
		splited = ft_strsplit(buf, ' ');
		if ((i = ft_parse(prm, splited, y)) < 0)
			return (-1);
		ft_free_tab(splited, i);
		y++;
	}
	return (0);
}
