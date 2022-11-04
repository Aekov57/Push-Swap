/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:58:07 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 20:27:09 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*lst_swap(t_list *ptr)
{
	if (ptr && ptr->head->next)
	{
		ptr->head->nbr ^= ptr->head->next->nbr;
		ptr->head->next->nbr ^= ptr->head->nbr;
		ptr->head->nbr ^= ptr->head->next->nbr;
	}
	return (ptr);
}

t_list	*lst_rotate(t_list *ptr)
{
	if (ptr->head)
	{
		add_tail_int(ptr, ptr->head->nbr);
		delete_first(ptr);
	}
	return (ptr);
}

t_list	*lst_push(t_list *lst, t_list *push)
{
	if (push->head)
	{
		add_head_int(lst, push->head->nbr);
		delete_first(push);
	}
	return (lst);
}

t_list	*reverse_rotate(t_list *ptr)
{
	if (ptr->tail)
	{
		add_head_int(ptr, ptr->tail->nbr);
		delete_last(ptr);
	}
	return (ptr);
}

void	double_revrotate(t_list *a, t_list *b)
{
	a = lst_rotate(a);
	b = lst_rotate(b);
	ft_printf("rrr\n");
}
