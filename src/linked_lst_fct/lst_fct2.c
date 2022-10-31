/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:38:08 by misimon           #+#    #+#             */
/*   Updated: 2022/10/28 16:11:50 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	delete_all_list(t_list *ptr)
{
	t_node	*tmp_node;
	t_node	*node;

	node = ptr->head;
	while (node)
	{
		tmp_node = node;
		node = node->next;
		free(tmp_node);
	}
	ptr->head = NULL;
	ptr->tail = NULL;
	ptr->size = 0;
}

void	insert_node_algo(t_node *node, t_node *new_node, t_list *ptr, int data)
{
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (0);
	new_node->nbr = data;
	node->next->prev = new_node;
	node->prev->next = new_node;
	new_node->prev = node->prev;
	new_node->next = node;
	ptr->size++;
}

t_list	*insert_node_int(t_list *ptr, size_t position, long data)
{
	t_node	*new_node;
	t_node	*node;
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	node = ptr->head;
	new_node = NULL;
	while (node && ++i <= position)
	{
		if (position == i)
		{
			if (!node->prev)
				add_head_int(ptr, data);
			if (!node->next)
				add_tail_int(ptr, data);
			else
				insert_node_algo(node, new_node, ptr, data);
		}
		node = node->next;
	}
	return (ptr);
}
