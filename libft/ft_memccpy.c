/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:50:45 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/25 16:21:25 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	unsigned char	x;
	size_t			index;

	index = 0;
	x = (unsigned char)c;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (csrc[index] && n > index)
	{
		if (csrc[index] == x)
		{
			cdest[index] = csrc[index];
			index++;
			return (&cdest[index]);
		}
		cdest[index] = csrc[index];
		index++;
	}
	return (NULL);
}
