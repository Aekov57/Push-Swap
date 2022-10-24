/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/10/24 18:15:28 by misimon          ###   ########.fr       */
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
		a = add_tail_int(a, nbr);
	}
}

void	check_arg(t_list *a, char **arg, int ac)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if (ac < 2)
		exit(1);
	tab = one_arg(tab, mult_in_one(arg, ac), 1);
	insert_arg(a, tab);
}

int	main(int ac, char **av)
{
	t_list	*a;

	a = create_list();
	check_arg(a, av, ac);
	//a = insert_node_int(a, 2, 80);
	view_lst(a);
	reverse_lst_view(a);
	return (1);
}
