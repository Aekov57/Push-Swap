/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:31 by misimon           #+#    #+#             */
/*   Updated: 2022/10/19 21:32:18 by misimon          ###   ########.fr       */
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

void	check_int(char **tab, int i, int i2)
{
	if (ft_atol(tab[i]) > (long)INT_MAX || ft_atol(tab[i]) < (long)INT_MIN)
		exit(ft_error() + free_tab(tab));
	while (tab[++i2])
	{
		if(atol(tab[i2]) == atol(tab[i]) && i != i2)
			exit(ft_error() + free_tab(tab));
	}
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	arg_parsing(char *str, int i, int check)
{
	if (!ft_isdigit(str[i]) && str[i] != ' ' && !ft_issign(str[i]))
		return (ft_error());
	if (str[i] == ' ' && (ft_isdigit(str[i + 1]) || ft_issign(str[i + 1]))
		&& check == 1)
		return (ft_error() + printf("multiple arg with multiple nbr in one arg\n"));
	if (ft_issign(str[i]) && (!ft_isdigit(str[i + 1])
			|| ft_isdigit(str[i - 1])))
		return (ft_error());
	return(1);
}

void	one_arg(char **tab, char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if(!arg_parsing(arg, i, 0))
			exit(0);
	}
	tab = ft_split(arg, ' ');
	if (tab == NULL)
		exit(ft_error());
	i = -1;
	while (tab[++i])
	{
		check_int(tab, i, -1);
		printf("%s\n", tab[i]);
	}
}

void	multiple_arg(char **tab)
{
	int	i;
	int	i2;

	i = -1;
	while (tab[++i])
	{
		i2 = -1;
		while (tab[i][++i2])
		{
			if(!arg_parsing(tab[i], i, 1))
				exit(0 + free_tab(tab));
		}
		check_int(tab, i, -1);
		printf("%s\n", tab[i]);
	}
}

char	**tab_multiple(char **arg)
{
	int i;
	int l;
	int i2;
	char **tab;

	i = 0;
	l = -1;
	tab = malloc(sizeof(arg));
	if (!tab)
		exit(ft_error());
	while (arg[++i])
	{
		++l;
		tab[l] = malloc(sizeof(char *) * ft_strlen(arg[i]) + 1);
		if(!tab[l])
		{
			free(tab);
			exit(ft_error());
		}
		i2 = -1;
		while (arg[i][++i2])
			tab[l][i2] = arg[i][i2];
		tab[l][i2] = '\0';
	}
	return (tab);
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
	{
		tab = tab_multiple(arg);
		multiple_arg(tab);
	}
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
