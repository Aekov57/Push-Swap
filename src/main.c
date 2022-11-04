/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 19:07:16 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	view_lst(ptr);
	return (ptr);
}

t_list *convert_lstn(t_list *a)
{
	t_list	*a_conv;
	t_node	*actual;
	t_node	*next;
	size_t	j;

	a_conv = create_list();
	actual = a->head;
	while (actual)
	{
		add_tail_int(a_conv, actual->nbr);
		actual = actual->next;
	}
	a_conv = simple_sort(a_conv);
	actual = a->head;
	view_lst(a);
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
	view_lst(a);
	return (a);
}

void	sort_hundred(t_list *a, t_list *b)
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
	while (b->head)
		pa(a, b);
	while (!check_sort(a) && a->head->nbr >= 0)
		ra(a);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = create_list();
	check_arg(a, av, ac);
	b = create_list();
	sort_case(a, b);
	delete_all_list(a);
	free(a);
	free(b);
	return (1);
}
