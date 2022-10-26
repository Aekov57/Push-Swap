/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:58:07 by misimon           #+#    #+#             */
/*   Updated: 2022/10/26 15:38:42 by misimon          ###   ########.fr       */
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
		ptr = add_tail_int(ptr, ptr->head->nbr);
		ptr = delete_position(ptr, 1);
	}
	return (ptr);
}

t_list	*lst_push(t_list *lst, t_list *push)
{
	if (lst->head && push->head)
	{
		lst = add_head_int(lst, push->head->nbr);
		push = delete_position(push, 1);
	}
	return (lst);
}

t_list	*reverse_rotate(t_list *ptr)
{
	if (ptr->tail)
	{
		ptr = add_head_int(ptr, ptr->tail->nbr);
		ptr = delete_position(ptr, ptr->size);
	}
	return (ptr);
}

void	double_revrotate(t_list *a, t_list *b)
{
	a = lst_rotate(a);
	b = lst_rotate(b);
	ft_printf("rrr\n");
}

void	double_rotate(t_list *a, t_list *b)
{
	a = lst_rotate(a);
	b = lst_rotate(b);
	ft_printf("rr\n");
}

void	double_lst_swap(t_list *a, t_list *b)
{
	a = lst_swap(a);
	b = lst_swap(b);
	ft_printf("ss\n");
}