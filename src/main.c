/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/10/28 16:24:45 by misimon          ###   ########.fr       */
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

void	check_arg(t_list *a, char **arg, int ac)
{
	char	**tab;
	int		i;

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

void	sort_five(t_list *a, t_list *b)
{
	b = lst_push(b, a);
	printf("pa\n");
	b = lst_push(b, a);
	printf("pa\n");
	sort_three(a);
	a = lst_push(a, b);
	printf("pb\n");
	a = lst_rotate(a);
	printf("ra\n");
	a = lst_push(a, b);
	printf("pb\n");
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
