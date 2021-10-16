/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:32:38 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/25 15:17:16 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

unsigned int	ft_checkmax(unsigned long nb, int pos)
{
	if (nb > 2147483647 && pos > 0)
		ft_error();
	if (nb > 2147483648 && pos < 0)
		ft_error();
	return ((int)nb * pos);
}

int	ft_atoi_spec(const char *str)
{
	unsigned long	nb;
	int				i;
	int				pos;

	pos = 1;
	i = 0;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			 || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			nb = (str[i++] - 48) + (nb * 10);
		else
			ft_error();
	}
	return (ft_checkmax(nb, pos));
}

void	*ft_realloc(void *ptr, size_t size)
{
	void			*new;

	if (!ptr)
	{
		new = ft_calloc_exit(size, sizeof(char));
		return (new);
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = ft_calloc_exit(size, sizeof(char));
	ft_strcpy(new, ptr);
	free(ptr);
	return (new);
}

char	*ft_strcpy(char *dest, char *src)
{
	int				i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
