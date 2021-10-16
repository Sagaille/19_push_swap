/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:37:41 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/23 12:51:13 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_quick_b_to_a_sub_1(t_struct *ps, int counter, int argc)
{
	if (ps->stack_b[1] > ps->med && ps->stack_b[1] != ps->min && \
ps->stack_b[1] != ps->min_plus_one && ps->stack_b[1] > ps->stack_b[0])
	{
		ft_rb_glo(ps);
		ft_pa_glo(ps, argc);
		counter++;
	}
	else if (ps->stack_b[0] > ps->med && ps->stack_b[0] \
	!= ps->min && ps->stack_b[0] != ps->min_plus_one)
	{
		ft_pa_glo(ps, argc);
		counter++;
	}
	else if (ps->stack_b[ps->ele_b - 1] > ps->med && ps->stack_b[ps->ele_b - \
1] != ps->min && ps->stack_b[ps->ele_b - 1] != ps->min_plus_one)
	{
		ft_rrb_glo(ps);
		counter++;
		ft_pa_glo(ps, argc);
	}
	else if (ft_shorter_route(ps, argc) == 1)
		ft_rrb_glo(ps);
	else
		ft_rb_glo(ps);
	return (counter);
}

int	ft_quick_b_to_a_sub_2(t_struct *ps, int counter, int argc, int temp)
{
	while (counter < temp && ps->ele_b > 2)
	{
		ft_check_switch_a(ps);
		if (ft_order_b(ps) == 1)
			break ;
		if (ft_exceptions(ps, temp, argc, counter) == 1)
			break ;
		if (ps->stack_b[0] != ps->min && ps->stack_b[0] != \
ps->min_plus_one && ps->stack_b[0] > ps->stack_b[ps->ele_b - 1])
		{
			counter++;
			ft_pa_glo(ps, argc);
		}
		else if (ps->stack_b[ps->ele_b - 1] != ps->min && \
		ps->stack_b[ps->ele_b - 1] != ps->min_plus_one)
			ft_rrb_glo(ps);
		else
			ft_rb_glo(ps);
	}
	return (counter);
}

int	ft_quick_b_to_a_sub_loop(t_struct *ps, int counter, int temp, int argc)
{
	while (counter < temp && ps->ele_b > 2 && temp - counter > 2)
	{
		if (ft_order_b(ps) == 1)
			break ;
		ft_selection_chunk(argc, ps, temp, counter);
		while (ft_over_med(ps) && ps->ele_b > 2 && temp - counter > 2)
		{
			ft_check_switch_a(ps);
			if (ft_order_b(ps) == 1)
				break ;
			counter = ft_quick_b_to_a_sub_1(ps, counter, argc);
		}
	}
	return (counter);
}

void	ft_quicksort_b_to_a(t_struct *ps, int temp, int argc, int x)
{
	int	counter;

	while (ps->ele_b > 2)
	{
		counter = 0;
		temp = ps->chunk[x];
		if (ft_order_b(ps) == 1)
			break ;
		counter = ft_quick_b_to_a_sub_loop(ps, counter, temp, argc);
		counter = ft_quick_b_to_a_sub_2(ps, counter, argc, temp);
		x--;
	}
	if (ps->stack_b[0] < ps->stack_b[1])
	{
		if (ps->stack_a[0] > ps->stack_a[1])
			ft_ss_glo(ps);
		else
			ft_sb_glo(ps);
	}
	if (ps->stack_a[0] > ps->stack_a[1])
		ft_ss_glo(ps);
	return ;
}
