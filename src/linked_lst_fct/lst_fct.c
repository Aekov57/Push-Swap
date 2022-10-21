/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:38:08 by misimon           #+#    #+#             */
/*   Updated: 2022/10/21 21:27:30 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void lst_push(t_list **lst, long nbr)
{
	t_list *ptr;
	ptr = malloc(sizeof(t_list));
	if(!ptr)
		exit(1);
	ptr->nbr = nbr;
	ptr->next = *lst;
	ptr->prev = NULL;
	if(*lst != NULL)
		(*lst)->prev = ptr;
	(*lst) = ptr;
}

void view_lst(t_list *lst)
{
	while (lst)
	{
		printf("%ld\n", lst->nbr);
		lst = lst->next;
	}
}