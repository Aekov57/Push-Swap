/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:38:08 by misimon           #+#    #+#             */
/*   Updated: 2022/10/24 18:13:51 by misimon          ###   ########.fr       */
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

t_list	*add_tail_int(t_list *ptr, long data)
{
	t_node	*new_node;

	if (!ptr)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = data;
	new_node->next = NULL;
	if (ptr->tail == NULL)
	{
		new_node->prev = NULL;
		ptr->head = new_node;
		ptr->tail = new_node;
	}
	else
	{
		ptr->tail->next = new_node;
		new_node->prev = ptr->tail;
		ptr->tail = new_node;
	}
	ptr->size++;
	return (ptr);
}

t_list	*add_head_int(t_list *ptr, long data)
{
	t_node	*new_node;

	if (!ptr)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = data;
	new_node->prev = NULL;
	if (ptr->head == NULL)
	{
		new_node->next = NULL;
		ptr->head = new_node;
		ptr->tail = new_node;
	}
	else
	{
		ptr->head->prev = new_node;
		new_node->next = ptr->head;
		ptr->head = new_node;
	}
	ptr->size++;
	return (ptr);
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

void	view_lst(t_list *lst)
{
	t_node	*temp_node;

	temp_node = lst->head;
	while (temp_node != NULL)
	{
		printf("%ld -> ", temp_node->nbr);
		temp_node = temp_node->next;
	}
	printf("NULL\n");
}

void	reverse_lst_view(t_list *lst)
{
	t_node	*temp_node;

	temp_node = lst->tail;
	printf("NULL");
	while (temp_node != NULL)
	{
		printf(" <- %ld", temp_node->nbr);
		temp_node = temp_node->prev;
	}
	printf("\n");
}
