/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:48:15 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/25 16:20:48 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	unsigned char		*csrc;
	size_t				index;

	index = 0;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	if (cdest == NULL && csrc == NULL)
		return (NULL);
	if (csrc < cdest)
	{
		while (n-- > 0)
			cdest[n] = csrc[n];
	}
	else
	{
		while (n > index)
		{
			cdest[index] = csrc[index];
			index++;
		}
	}
	return (cdest);
}
