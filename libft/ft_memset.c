/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:17:05 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/25 16:20:36 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*memo;

	memo = (unsigned char *)str;
	index = 0;
	while (n > index)
	{
		memo[index] = (unsigned char)c;
		index++;
	}
	return (str);
}
