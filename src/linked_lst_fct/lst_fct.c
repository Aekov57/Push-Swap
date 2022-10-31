/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:38:08 by misimon           #+#    #+#             */
/*   Updated: 2022/10/28 16:08:56 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*create_list(void)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->head = NULL;
	ptr->tail = NULL;
	ptr->size = 0;
	return (ptr);
}

void	add_tail_int(t_list *ptr, long data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->nbr = data;
	new_node->prev = ptr->tail;
	new_node->next = NULL;
	if (ptr->tail)
		ptr->tail->next = new_node;
	else
		ptr->head = new_node;
	ptr->tail = new_node;
	ptr->size++;
}

void	add_head_int(t_list *ptr, long data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->nbr = data;
	new_node->prev = NULL;
	new_node->next = ptr->head;
	if (ptr->head)
		ptr->head->prev = new_node;
	else
		ptr->tail = new_node;
	ptr->head = new_node;
	ptr->size++;
}

void	delete_last(t_list *ptr)
{
	t_node	*node;

	node = ptr->tail;
	if (!node)
		exit (EXIT_FAILURE);
	ptr->tail = node->prev;
	if (ptr->tail)
		ptr->tail->next = NULL;
	else
		ptr->head = NULL;
	free(node);
	ptr->size--;
}

void	delete_first(t_list *ptr)
{
	t_node	*node;

	node = ptr->head;
	if (!node)
		exit(EXIT_FAILURE);
	ptr->head = node->next;
	if (ptr->head)
		ptr->head->prev = NULL;
	else
		ptr->head = NULL;
	free(node);
	ptr->size--;
}
