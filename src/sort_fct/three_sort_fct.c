/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:58:07 by misimon           #+#    #+#             */
/*   Updated: 2022/10/28 15:44:20 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	three_case1(t_list *a)
{
	a = lst_swap(a);
	ft_printf("sa\n");
}

void	three_case2(t_list *a)
{
	a = lst_swap(a);
	ft_printf("sa\n");
	a = reverse_rotate(a);
	ft_printf("rra\n");
}

void	three_case3(t_list *a)
{
	a = lst_rotate(a);
	ft_printf("ra\n");
}

void	three_case4(t_list *a)
{
	a = lst_swap(a);
	ft_printf("sa\n");
	a = lst_rotate(a);
	ft_printf("ra\n");
}

t_list	*sort_three(t_list *a)
{
	if (a->head->nbr > a->head->next->nbr && a->head->nbr < a->tail->nbr)
		three_case1(a);
	else if (a->head->nbr > a->tail->nbr && a->head->nbr > a->head->next->nbr
		&& a->head->next->nbr > a->tail->nbr)
		three_case2(a);
	else if (a->head->nbr > a->head->next->nbr && a->head->nbr > a->tail->nbr
		&& a->tail->nbr > a->head->next->nbr)
		three_case3(a);
	else if (a->head->nbr < a->head->next->nbr
		&& a->head->next->nbr > a->tail->nbr && a->head->nbr < a->tail->nbr)
		three_case4(a);
	else if (a->head->nbr < a->head->next->nbr && a->head->nbr > a->tail->nbr
		&& a->tail->nbr < a->head->next->nbr)
	{
		a = reverse_rotate(a);
		ft_printf("rra\n");
	}
	return (a);
}