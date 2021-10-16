/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:56:06 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:58:14 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_min_max_med(int argc, t_struct *ps)
{
	int	i;

	i = 0;
	ps->max = ps->stack_a[i];
	ps->min = ps->stack_a[i];
	while (i < argc - 1)
	{
		if (ps->stack_a[i] > ps->max)
			ps->max = ps->stack_a[i];
		if (ps->stack_a[i] < ps->min)
			ps->min = ps->stack_a[i];
		i++;
	}
	return (1);
}

int	ft_sort(int argc, t_struct *ps)
{
	ft_ps_init(ps, argc);
	ft_min_max_med(argc, ps);
	ft_quicksort(argc, ps);
	if (ps->bonus != 0)
	{
		ft_putstr_fd("\n\x1B[35mSTACK B\n", 1);
		ft_print_tab(ps->stack_b, argc);
		ft_putstr_fd("\n\x1B[35mSTACK A\n", 1);
		ft_print_tab(ps->stack_a, argc);
	}
	if (ps->bonus != 0)
	{
		ft_putstr_fd("\n\x1B[35mMOVES = ", 1);
		ft_putnbr_fd(ps->moves, 1);
		ft_putstr_fd("\n\x1B[0m", 1);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
