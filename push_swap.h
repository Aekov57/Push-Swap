/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:06 by misimon           #+#    #+#             */
/*   Updated: 2022/10/12 18:15:50 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/**** STRUCTURE DECLARATION ****/

typedef struct s_list
{
	long			nbr;
	struct s_list	*next;
	struct s_list	*last;
}	t_list;

/**** INT FUNCTION ****/

int		error(void);

/**** VOID FUNCTION ****/

void	free_tab(char **tab);

#endif