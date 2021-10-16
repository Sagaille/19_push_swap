/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:53:44 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:44:27 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t count)
{
	size_t	i;
	size_t	y;

	if (ft_strlen(lit) == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < count)
	{
		if (big[i] == lit[0])
		{
			y = 1;
			while ((lit[y] != '\0') && (big[i + y] == lit[y]) \
				 && (i + y < count))
				y++;
			if (lit[y] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
