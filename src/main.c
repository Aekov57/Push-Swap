/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/11/01 14:51:12 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

long	check_high(t_list *a)
{
	t_node	*node;
	long	max;
	long	i;

	i = 0;
	node = a->head;
	max = node->nbr;
	while (node && node->next != NULL)
	{
		if (node->nbr > node->next->nbr)
			max = node->nbr;
		node = node->next;
	}
	return (max);
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


long	check_min(t_list *a)
{
	t_node	*node;
	long	min;

	node = a->head;
	min = node->nbr;
	while (node && node->next != NULL)
	{
		if (node->nbr < node->next->nbr)
			min = node->nbr;
		node = node->next;
	}
	return (min);
}

int	check_sort(t_list *a)
{
	t_node	*node;

	node = a->head;
	while (node && node->next != NULL)
	{
		if (node->nbr < node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

void	sort_five(t_list *a, t_list *b)
{
	b = lst_push(b, a);
	b = lst_push(b, a);
	sort_three(a);
	view_lst(a);
	view_lst(b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = create_list();
	check_arg(a, av, ac);
	b = create_list();
	view_lst(a);
	if (a->size == 3)
		a = sort_three(a);
	if (a->size == 5)
		sort_five(a, b);
	view_lst(a);
	delete_all_list(a);
	free(a);
	free(b);
	return (1);
}
