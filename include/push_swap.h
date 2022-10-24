/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:06 by misimon           #+#    #+#             */
/*   Updated: 2022/10/24 18:07:49 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**** INCLUDE ****/
# include "../libft/include/libft.h"

/**** STRUCTURE ****/
typedef struct s_node
{
	long			nbr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	size_t			size;
	t_node			*head;
	t_node			*tail;
}	t_list;

/**** FUNCTION ****/

t_list	*create_list(void);
t_list	*add_tail_int(t_list *ptr, long data);
t_list	*add_head_int(t_list *ptr, long data);
t_list	*insert_node_int(t_list *ptr, size_t position, long data);
void	reverse_lst_view(t_list *lst);

long	ft_atol(const char *str);
void	check_int(char **tab, int i, int i2);
int		arg_parsing(char *str, int i);
char	**one_arg(char **tab, char *arg, int check);
char	*mult_in_one(char **arg, int ac);
void	check_arg(t_list *a, char **arg, int ac);

void	view_lst(t_list *lst);
#endif
