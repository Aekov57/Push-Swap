/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:21:33 by misimon           #+#    #+#             */
/*   Updated: 2022/10/19 02:36:36 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*l;

	l = (unsigned char *)s;
	while (n--)
	{
		if (*l == (unsigned char)c)
			return (l);
		l++;
	}
	return (NULL);
}
