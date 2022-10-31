/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:02:10 by misimon           #+#    #+#             */
/*   Updated: 2022/10/28 16:03:13 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
