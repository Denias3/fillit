/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:42 by emeha             #+#    #+#             */
/*   Updated: 2018/12/31 14:50:03 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		location_check(char **matrix, t_tetr *elem, int i, int j)
{
	int a;
	int b;

	a = 0;
	if (i + elem->height > M_SIZE(matrix[0]) ||
			j + elem->width > M_SIZE(matrix[0]))
		return (0);
	while (a < elem->height)
	{
		b = 0;
		while (b < elem->width)
		{
			if (elem->data[elem->y + a][elem->x + b] == 1)
			{
				if (matrix[i + a][j + b] != '.')
					return (0);
			}
			b++;
		}
		a++;
	}
	return (1);
}

int		put_tetr(char **matrix, t_tetr *elem, int i, int j)
{
	int t;
	int o;
	int a;

	t = j;
	if ((!matrix || !(*matrix) || !elem) || ((i + elem->height >
			M_SIZE(matrix[0])) || (j + elem->width > M_SIZE(matrix[0]))))
		return (0);
	if (elem->height <= M_SIZE(matrix[0]) && elem->width <= M_SIZE(matrix[0]))
	{
		if (!location_check(matrix, elem, i, j))
			return (0);
		a = -1;
		while (++a < elem->height)
		{
			o = -1;
			j = t;
			while (++o < elem->width)
			{
				if (elem->data[elem->y + a][elem->x + o] == 1)
					matrix[i][j] = elem->name;
				j++;
			}
			i++;
		}
	}
	return (1);
}

int		all_prev_not_placed(char **matrix, t_tetr *elem)
{
	t_tetr	*tmp;

	tmp = elem->prev;
	if (tmp == NULL)
		return (1);
	while (tmp->prev != NULL)
	{
		if (is_placed(matrix, tmp) == 1)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

int		place_one(char **matrix, t_tetr *elem, int i, int j)
{
	while (elem->g_y != -1)
	{
		calc_next_tetr_pos(elem, matrix);
		if (elem->g_y == M_SIZE(matrix[0]) - 1 &&
				elem->g_x == M_SIZE(matrix[0]) - 1)
			return (0);
		if (put_tetr(matrix, elem, elem->g_y, elem->g_x))
		{
			elem->state = 1;
			return (1);
		}
	}
	while (++i < M_SIZE(matrix[0]))
	{
		j = -1;
		while (++j < M_SIZE(matrix[0]))
			if (put_tetr(matrix, elem, i, j))
			{
				elem->state = 1;
				elem->g_x = j;
				elem->g_y = i;
				return (1);
			}
	}
	return (0);
}

int		place_all1(char **matrix, t_tetr *elem)
{
	t_tetr *head;

	head = elem;
	while (count_elems(head) - count_status_elems(head) && elem != NULL)
	{
		if (place_one(matrix, elem, -1, -1))
			elem = elem->next;
		else
		{
			if (elem->name == head->name)
				return (2);
			remove_elem_from_matrix(matrix, elem->prev);
			if (!place_one(matrix, elem->prev, -1, -1))
			{
				if (elem->prev->prev == NULL)
					return (2);
				remove_elem_from_matrix(matrix, elem->prev->prev);
				elem = elem->prev->prev;
			}
		}
	}
	return (0);
}
