/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:06:00 by palan             #+#    #+#             */
/*   Updated: 2018/12/20 13:26:01 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	push_back(t_tetr **head, t_tetr *elem)
{
	t_tetr *tmp;

	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	elem->prev = tmp;
}

t_tetr	*tetrnew(int **data)
{
	t_tetr	*new;

	new = (t_tetr*)malloc(sizeof(t_tetr));
	if (new == NULL)
		return (NULL);
	if (data == NULL)
		new->data = NULL;
	else
		new->data = data;
	new->x = -1;
	new->y = -1;
	new->g_x = -1;
	new->g_y = -1;
	new->height = -1;
	new->width = -1;
	new->state = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int		count_elems(t_tetr *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int		count_status_elems(t_tetr *head)
{
	int i;

	i = 0;
	while (head)
	{
		if (head->state == 1)
			i++;
		head = head->next;
	}
	return (i);
}

void	refresh(t_tetr *elem)
{
	while (elem)
	{
		elem->state = 0;
		elem->g_y = -1;
		elem->g_x = -1;
		elem = elem->next;
	}
}
