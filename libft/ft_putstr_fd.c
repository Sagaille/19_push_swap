/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:54:01 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/25 16:19:46 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s == NULL || fd < 0 || fd > FOPEN_MAX)
		return ;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
}
