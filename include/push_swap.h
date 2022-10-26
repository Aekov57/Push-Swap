/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:06 by misimon           #+#    #+#             */
/*   Updated: 2022/10/26 15:39:12 by misimon          ###   ########.fr       */
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
t_list	*delete_position(t_list *ptr, size_t position);
t_list	*lst_swap(t_list *ptr);
t_list	*lst_rotate(t_list *ptr);
t_list	*lst_push(t_list *lst, t_list *push);
t_list	*reverse_rotate(t_list *ptr);
void	double_revrotate(t_list *a, t_list *b);
void	double_rotate(t_list *a, t_list *b);
void	double_lst_swap(t_list *a, t_list *b);
void	delete_all_list(t_list *ptr);
void	reverse_lst_view(t_list *lst);

long	ft_atol(const char *str);
void	check_int(char **tab, int i, int i2);
int		arg_parsing(char *str, int i);
char	**one_arg(char **tab, char *arg, int check);
char	*mult_in_one(char **arg, int ac);
void	check_arg(t_list *a, char **arg, int ac);

void	view_lst(t_list *lst);
#endif
