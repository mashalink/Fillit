/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:04:07 by mlink             #+#    #+#             */
/*   Updated: 2019/12/02 10:22:43 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	*ft_coord_min_max(char *buf)
{
	int		i;
	t_point	*points;

	if (!(points = malloc(sizeof(t_point))))
		return (NULL);
	points->x_min = 3;
	points->x_max = 0;
	points->y_min = 3;
	points->y_max = 0;
	i = -1;
	while (++i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i % 5) < points->x_min)
				points->x_min = i % 5;
			if ((i % 5) > points->x_max)
				points->x_max = i % 5;
			if ((i / 5) < points->y_min)
				points->y_min = i / 5;
			if ((i / 5) > points->y_max)
				points->y_max = i / 5;
		}
	}
	return (points);
}

char			**ft_trim(char *buf, int *height)
{
	t_point	*points;
	char	**new;
	int		i;

	points = ft_coord_min_max(buf);
	new = (char **)malloc(sizeof(char*) * (points->y_max - points->y_min + 1));
	if (!new || !points)
		return (0);
	i = 0;
	while (points->y_max >= points->y_min)
	{
		new[i] = ft_strsub(buf, (points->y_min * 5 + points->x_min),\
								points->x_max - points->x_min + 1);
		if (!new[i])
			return (0);
		i++;
		points->y_min++;
	}
	*height = i;
	free(points);
	return (new);
}
