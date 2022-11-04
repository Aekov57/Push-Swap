/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:31:25 by misimon           #+#    #+#             */
/*   Updated: 2022/11/04 14:50:47 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_int(char **tab, int i, int i2)
{
	if (ft_atol(tab[i]) > (long)INT_MAX || ft_atol(tab[i]) < (long)INT_MIN)
		exit(ft_error() + free_tab(tab));
	while (tab[++i2])
	{
		if (ft_atol(tab[i2]) == ft_atol(tab[i]) && i != i2)
			exit(ft_error() + free_tab(tab));
	}
}

int	arg_parsing(char *str, int i)
{
	if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\n' && !ft_issign(str[i]))
		return (ft_error());
	if (ft_issign(str[i]) && (!ft_isdigit(str[i + 1])
			|| ft_isdigit(str[i - 1])))
		return (ft_error());
	return (1);
}

char	**one_arg(char **tab, char *arg, int check)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg_parsing(arg, i) != 1)
			exit(0);
	tab = ft_split(arg, ' ');
	if (check == 1)
		free(arg);
	if (tab == NULL)
		exit(ft_error());
	i = -1;
	while (tab[++i])
		check_int(tab, i, -1);
	return (tab);
}

char	*mult_in_one(char **arg, int ac)
{
	char	*str;
	int		i;

	i = 0;
	str = calloc(1, sizeof(char));
	while (++i < ac)
	{
		str = ft_strfjoin(str, arg[i]);
		if (i + 1 != ac)
			str = ft_strfjoin(str, " ");
	}
	return (str);
}