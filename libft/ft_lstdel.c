/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:22:24 by palan             #+#    #+#             */
/*   Updated: 2018/12/02 13:58:06 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*node;

	if (!del || !alst)
		return ;
	node = *alst;
	while (node != NULL)
	{
		tmp = node->next;
		del(node->content, node->content_size);
		free(node);
		node = tmp;
	}
	*alst = NULL;
}
