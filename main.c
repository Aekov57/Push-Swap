/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/10/13 21:02:43 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_int_limit(char **tab, int i, int check)
{
	if (ft_atol(tab[i]) > (long)INT_MAX || ft_atol(tab[i]) < (long)INT_MIN)
	{
		if (check == 1)
			free_tab(tab);
		exit(error() + printf("int = %ld", ft_atol(tab[i])));
	}
}

void	one_arg(char **tab, char *arg)
{
	int	i;
	int sign;

	i = -1;
	sign = 0;
	while (arg[++i])
	{
		if (arg[i] == '-' || arg[i] == '+')
		{

		}
		if (!ft_isdigit(arg[i]) && arg[i] != ' ')
			exit (error() + printf("%c%c a %d", arg[i - 1], arg[i], i));
	}
	tab = ft_split(arg, ' ');
	i = 0;
	while (tab[i])
	{
		check_int_limit(tab, i, 1);
		printf("%s\n", tab[i++]);
	}
}

void	mulltiple_arg(char **tab, int ac)
{
	int	i;
	int	i2;

	i = 0;
	while (++i < ac && ac > 2)
	{
		i2 = 0;
		while (tab[i][i2])
		{
			if (!ft_isdigit(tab[i][i2++]))
				exit(error());
			check_int_limit(tab, i, 0);
		}
		printf("%s\n", tab[i]);
	}
}

t_list	check_arg(t_list a, char **arg, int ac)
{
	char	**tab;

	tab = NULL;
	if (ac < 2)
		exit(1);
	else if (ac == 2)
		one_arg(tab, arg[1]);
	else
		mulltiple_arg(arg, ac);
	return (a);
}

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	int		i;

	a.nbr = 0;
	(void)b;
	check_arg(a, av, ac);
	i = 0;
	return (1);
}

// TODO: Vérifier si les arg sont stocker dans 1 seul argv ou dans plusieurs !
// TODO: Mettre les arg une fois convertis dans la liste chainé A !