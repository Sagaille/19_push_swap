/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:59:18 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/25 16:22:48 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	int				i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	long int		i;
	char			*str;
	long int		negatif;
	long int		nb;

	negatif = 0;
	nb = (long int)n;
	if (nb < 0)
	{
		negatif = 1;
		nb = -nb;
	}
	i = ft_len(nb) + negatif;
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (negatif == 1)
		str[0] = '-';
	return (str);
}
