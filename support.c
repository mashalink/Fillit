/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:27:09 by mlink             #+#    #+#             */
/*   Updated: 2019/12/02 10:22:15 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim	*ft_create_elem(char **data, char letter, int height)
{
	t_tetrim	*list;

	list = malloc(sizeof(t_tetrim));
	if (list)
	{
		list->figure = data;
		list->letter = letter;
		list->height = height;
		list->next = NULL;
	}
	return (list);
}

int			ft_map_size(int n)
{
	int size;

	size = 2;
	while (size * size < n * 4)
		size++;
	return (size);
}

size_t		ft_tetrim_size(t_tetrim *list)
{
	t_tetrim	*temp;
	size_t		size;

	temp = list;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void		ft_map_zeroup(char *map, char a, char b)
{
	if (!map)
		return ;
	while (*map)
	{
		if (*map == a)
			*map = b;
		map++;
	}
}

void		tetr_del(t_tetrim **tetr)
{
	t_tetrim	*head;
	t_tetrim	*strsave;
	char		**figure;
	int			height;

	head = *tetr;
	while (head)
	{
		figure = head->figure;
		height = head->height;
		strsave = head->next;
		free(head);
		head = strsave;
		while (--height >= 0)
			free(figure[height]);
		free(figure);
	}
	*tetr = NULL;
}
