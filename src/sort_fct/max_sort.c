/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:36:01 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 20:42:50 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*simple_sort(t_list *ptr)
{
	t_node	*next;
	t_node	*actual;

	actual = ptr->head;
	while (!check_sort(ptr) && actual)
	{
		next = ptr->head;
		while (next)
		{
			if (actual->nbr < next->nbr)
			{
				actual->nbr ^= next->nbr;
				next->nbr ^= actual->nbr;
				actual->nbr ^= next->nbr;
			}
			next = next->next;
		}
		actual = actual->next;
	}
	return (ptr);
}

void	convert_alst(t_list *a, t_list *a_conv)
{
	t_node	*next;
	t_node	*actual;
	size_t	j;

	actual = a->head;
	while (actual)
	{
		next = a_conv->head;
		j = 0;
		while (next)
		{
			j++;
			if (actual->nbr == next->nbr)
			{
				actual->nbr = j;
				break ;
			}
			next = next->next;
		}
		actual = actual->next;
	}
}

t_list	*convert_lstn(t_list *a)
{
	t_list	*a_conv;
	t_node	*actual;

	a_conv = create_list();
	actual = a->head;
	while (actual)
	{
		add_tail_int(a_conv, actual->nbr);
		actual = actual->next;
	}
	a_conv = simple_sort(a_conv);
	convert_alst(a, a_conv);
	delete_all_list(a_conv);
	free(a);
	return (a);
}

void	radix_pw(t_list *a, t_list *b)
{
	size_t	j;
	size_t	l;

	l = 0;
	while (!check_sort(a))
	{
		j = a->size;
		while (j-- && !check_sort(a))
		{
			if (!(a->head->nbr >> l & 1))
				pb(a, b);
			else
				ra(a);
		}
		j = b->size;
		l++;
		while (j-- && !check_sort(a))
		{
			if (b->head->nbr >> l & 1)
				pa(a, b);
			else
				rb(b);
		}
	}
}

void	sort_hundred(t_list *a, t_list *b)
{
	radix_pw(a, b);
	while (b->head)
		pa(a, b);
	while (!check_sort(a) && a->head->nbr >= 0)
		ra(a);
}
