/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:22:48 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 20:27:04 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_list *a)
{
	a = lst_swap(a);
	ft_printf("sa\n");
}

void	sb(t_list *b)
{
	b = lst_swap(b);
	ft_printf("sb\n");
}

void	pa(t_list *a, t_list *b)
{
	a = lst_push(a, b);
	ft_printf("pa\n");
}

void	pb(t_list *a, t_list *b)
{
	b = lst_push(b, a);
	ft_printf("pb\n");
}
