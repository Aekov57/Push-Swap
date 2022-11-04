/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:47:37 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 13:51:24 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	min_max_on_top(t_list *a, t_list *b)
{
	long	i;
	long	j;
	size_t	l;

	i = check_min(a);
	j = check_max(a);
	l = 0;
	while (l <= a->size)
	{
		if (a->head->nbr == i)
			pb(a, b);
		else if (a->head->nbr == j)
			pb(a, b);
		else
			ra(a);
		l++;
	}
}

void	sort_min_max(t_list *a, t_list *b, long j)
{
	pa(a, b);
	if (a->head->nbr == j)
		ra(a);
}

void	min_on_top(t_list *a, t_list *b)
{
	long	i;
	size_t	l;

	i = check_min(a);
	l = 0;
	while (l <= a->size)
	{
		if (a->head->nbr == i)
			pb(a, b);
		else
			ra(a);
		l++;
	}
}

void	sort_five(t_list *a, t_list *b)
{
	long	j;

	j = check_max(a);
	if (a->size == 5)
		min_max_on_top(a, b);
	else
		min_on_top(a, b);
	a = sort_three(a);
	if (b->size == 2)
		sort_min_max(a, b, j);
	sort_min_max(a, b, j);
}