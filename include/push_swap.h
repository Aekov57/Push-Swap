/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:06 by misimon           #+#    #+#             */
/*   Updated: 2022/10/21 21:18:00 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**** INCLUDE ****/
# include "../libft/include/libft.h"

/**** STRUCTURE ****/
typedef struct s_list
{
	long			nbr;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*first;
	struct s_list	*last;
}	t_list;

/**** FUNCTION ****/

long	ft_atol(const char *str);
void	check_int(char **tab, int i, int i2);
int		arg_parsing(char *str, int i);
void	one_arg(char **tab, char *arg, int check);
char	*mult_in_one(char **arg, int ac);
void	check_arg(t_list *a, char **arg, int ac);

void	lst_push(t_list **lst, long nbr);
void	view_lst(t_list *lst);
#endif
