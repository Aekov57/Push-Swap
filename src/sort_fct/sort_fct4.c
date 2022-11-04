/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:23:43 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 20:27:02 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	double_rotate(t_list *a, t_list *b)
{
	a = lst_rotate(a);
	b = lst_rotate(b);
	ft_printf("rr\n");
}

void	ss(t_list *a, t_list *b)
{
	a = lst_swap(a);
	b = lst_swap(b);
	ft_printf("ss\n");
}
