/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:21:51 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 20:28:59 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_list *a)
{
	a = lst_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_list *b)
{
	b = lst_rotate(b);
	ft_printf("rb\n");
}

void	rra(t_list *a)
{
	a = reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_list *b)
{
	b = reverse_rotate(b);
	ft_printf("rrb\n");
}
