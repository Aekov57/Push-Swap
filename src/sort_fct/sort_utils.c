/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:51:04 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 20:29:47 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_sort(t_list *a)
{
	t_node	*node;

	node = a->head;
	while (node && node->next)
	{
		if (node->nbr > node->next->nbr)
			return (FALSE);
		node = node->next;
	}
	node = a->head;
	return (TRUE);
}

long	check_min(t_list *a)
{
	t_node	*node;
	long	min;

	node = a->head;
	min = node->nbr;
	while (node && node->next)
	{
		if (min > node->next->nbr)
			min = node->next->nbr;
		node = node->next;
	}
	return (min);
}

long	check_max(t_list *a)
{
	t_node	*node;
	long	max;

	node = a->head;
	max = node->nbr;
	while (node && node->next)
	{
		if (max < node->next->nbr)
			max = node->next->nbr;
		node = node->next;
	}
	return (max);
}
