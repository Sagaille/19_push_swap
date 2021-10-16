/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:47:52 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/23 15:07:28 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_exceptions(t_struct *ps, int temp, int argc, int counter)
{
	ft_max_b(ps);
	if (temp - counter == 2 && ps->stack_b[0] < \
	 ps->stack_b[1] && ps->stack_b[1] == \
	ps->max_b && ps->stack_b[0] == ps->max_b_one)
	{
		ft_sb_glo(ps);
		ft_pa_glo(ps, argc);
		ft_check_switch_a(ps);
		ft_pa_glo(ps, argc);
		return (1);
	}
	else if (temp - counter == 2 && \
	ps->stack_b[0] == ps->max_b && ps->stack_b[1] == ps->max_b_one)
	{
		ft_pa_glo(ps, argc);
		ft_check_switch_a(ps);
		ft_pa_glo(ps, argc);
		return (1);
	}
	else
		return (0);
}

int	ft_quicksort(int argc, t_struct *ps)
{
	int	temp;
	int	x;

	ft_order(ps);
	ps->order_b = 2;
	if (ft_switch_down_a(ps, 0) == 1)
		exit(EXIT_SUCCESS);
	ft_selection(argc, ps);
	while (ps->order > 0)
	{
		ft_order(ps);
		temp = ps->order;
		x = ft_quicksort_a_to_b(ps, temp, argc, 0) + 1;
		ft_quicksort_b_to_a(ps, temp, argc, x);
		ft_order(ps);
	}
	if (ps->stack_b[1] > ps->stack_b[0])
		ft_sb_glo(ps);
	while (ps->ele_b > 0)
	{
		if (ps->stack_a[1] < ps->stack_a[0])
			ft_sa_glo(ps);
		ft_pa_glo(ps, argc);
	}
	return (1);
}
