/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:32:38 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:38:53 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	*ft_calloc_exit(size_t num, size_t size)
{
	void	*result;

	result = malloc(size * num);
	if (!result)
		return (NULL);
	ft_bzero(result, size * num);
	return (result);
}

void	ft_ps_init(t_struct *ps, int argc)
{
	int	i;

	i = 0;
	ps->i = 0;
	ps->elements_a = argc - 1;
	ps->ele_b = 0;
	ps->moves = 0;
	while (i < 500)
	{
		ps->chunk[i] = 0;
		i++;
	}
}

void	ft_print_tab(int *tab, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		ft_putstr_fd("\x1B[33m", 1);
		ft_putnbr_fd(tab[i], 1);
		ft_putstr_fd("\x1B[0m\n", 1);
		i++;
	}
}

int	ft_ok_ko(t_struct *ps, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (ps->stack_a[i] > ps->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}
