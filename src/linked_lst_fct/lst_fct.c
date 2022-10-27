/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:38:08 by misimon           #+#    #+#             */
/*   Updated: 2022/10/27 21:32:24 by misimon          ###   ########.fr       */
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

//int delete_first()
//{

//}

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

t_list	*delete_position(t_list *ptr, size_t position)
{
	t_node	*node;
	size_t	i;

	if (!ptr)
		return (NULL);
	node = ptr->head;
	i = 0;
	while (node && ++i <= position)
	{
		if (position == i)
		{
			if (node->next == NULL)
			{
				ptr->tail = node->prev;
				ptr->tail->next = NULL;
			}
			if (node->prev == NULL)
			{
				ptr->head = node->next;
				ptr->head->prev = NULL;
			}
			else
			{
				node->next->prev = node->prev;
				node->prev->next = node->next;
			}
			free(node);
			ptr->size--;
		}
		else
		{
			node = node->next;
		}
	}
	return (ptr);
}

void	delete_all_list(t_list *ptr)
{
	t_node	*node;

	while (ptr && ptr->size-- != 0)
	{
		node = ptr->head->next;
		free(ptr->head);
		ptr->head = node;
	}
	ptr->head = NULL;
	ptr->tail = NULL;
	ptr->size = 0;
}

void	view_lst(t_list *lst)
{
	t_node	*temp_node;

	if (!lst->head)
		exit (0 + printf("NULL"));
	temp_node = lst->head;
	while (temp_node != NULL)
	{
		printf("%ld -> ", temp_node->nbr);
		temp_node = temp_node->next;
	}
	printf("NULL\n");
}

int	lst_len(t_list *lst)
{
	int		i;
	t_node	*node;

	node = lst->head;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	reverse_lst_view(t_list *lst)
{
	t_node	*temp_node;

	if (!lst->tail)
		exit (0 + printf("NULL"));
	temp_node = lst->tail;
	printf("NULL");
	while (temp_node != NULL)
	{
		printf(" <- %ld", temp_node->nbr);
		temp_node = temp_node->prev;
	}
	printf("\n");
}
