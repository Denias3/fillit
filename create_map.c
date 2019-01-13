/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:26 by emeha             #+#    #+#             */
/*   Updated: 2018/12/22 13:54:00 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shape_size(t_tetr **head)
{
	t_tetr	*temp;
	int		y;
	int		x;

	temp = *head;
	while (temp) {
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
				if (temp->data[y][x] == 1)
				{
					if (temp->height < y)
						temp->height = y;
					if (temp->width < x)
						temp->width = x;
				}
		}
		temp->height = temp->height - temp->y + 1;
		temp->width = temp->width - temp->x + 1;
		temp = temp->next;
	}
}

char	**create_matrix(int size)
{
	char	**map;
	int		i;
	int		j;

	map = (char**)malloc(sizeof(char*) * (size + 1));
	i = 0;
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char*) * (size + 1));
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		calc_map_size(int tetrs)
{
	int		i;

	i = tetrs;
	if (tetrs * tetrs < tetrs * 4)
	{
		while (i * i < tetrs * 4)
			i++;
		return (i);
	}
	else if (tetrs * tetrs > tetrs * 4)
	{
		while (i * i > tetrs * 4)
			i--;
		if (i * i == tetrs * 4)
			return (i);
		return (i + 1);
	}
	return (i);
}
