/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:06 by misimon           #+#    #+#             */
/*   Updated: 2022/10/21 17:32:56 by misimon          ###   ########.fr       */
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

#endif
