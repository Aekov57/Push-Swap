/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/10/21 21:28:53 by misimon          ###   ########.fr       */
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

void	check_arg(t_list *a, char **arg, int ac)
{
	char	**tab;

	(void)a;
	tab = NULL;
	if (ac < 2)
		exit(1);
	one_arg(tab, mult_in_one(arg, ac), 1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	b;

	b.nbr = 0;
	a = NULL;
	check_arg(a, av, ac);
	return (1);
}

// TODO: Vérifier si les arg sont stocker dans 1 seul argv ou dans plusieurs !
// TODO: Mettre les arg une fois convertis dans la liste chainé A !
