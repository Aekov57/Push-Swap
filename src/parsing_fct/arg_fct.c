/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:54:12 by misimon           #+#    #+#             */
/*   Updated: 2022/11/05 01:05:21 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		l;

	l = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			l = -1;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	result *= l;
	return (result);
}

void	insert_arg(t_list *a, char **tab)
{
	int		i;
	long	nbr;

	i = -1;
	while (tab[++i])
	{
		nbr = ft_atol(tab[i]);
		add_tail_int(a, nbr);
	}
}

void	check_arg(t_list *a, char **arg, int ac)
{
	char	**tab;
	long	i;

	i = 0;
	tab = NULL;
	if (ac < 2)
	{
		free(a);
		exit(1);
	}
	tab = one_arg(tab, mult_in_one(arg, ac), 1);
	insert_arg(a, tab);
	free_tab(tab);
}

void	sort_case(t_list *a, t_list *b)
{
	t_list	*a_conv;

	if (a->size == 2)
	{
		if (a->head->nbr > a->tail->nbr)
			sa(a);
	}
	else if (a->size == 3)
		a = sort_three(a);
	else if (a->size > 3 && a->size <= 5)
	{
		if (check_sort(a) != TRUE)
			sort_five(a, b);
	}
	else if (a->size > 5 && !check_sort(a))
	{
		a_conv = convert_lstn(a);
		sort_hundred(a_conv, b);
	}
}
