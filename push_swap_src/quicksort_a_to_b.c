/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:03:10 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/23 12:41:15 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	multi_rra(t_struct *ps)
{
	ft_rra_glo(ps);
	ft_rra_glo(ps);
	ft_rra_glo(ps);
}

void	ft_quicksort_a_to_b_sub(t_struct *ps, int temp, int argc)
{
	if (ps->stack_a[ps->elements_a - 1] < ps->med && \
		ps->stack_a[ps->elements_a - 1] < ps->max)
		ft_rra_glo(ps);
	else if (ps->elements_a - 2 >= 0 && ps->stack_a[ps->elements_a - 2] < ps->med && \
	ps->stack_a[ps->elements_a - 2] < ps->max && temp > 8)
	{
		ft_rra_glo(ps);
		ft_rra_glo(ps);
	}
	else if (ps->elements_a - 3 >= 0 && ps->stack_a[ps->elements_a - 3] < ps->med && \
ps->stack_a[ps->elements_a - 3] < ps->max && temp > 10 && argc > 120)
		multi_rra(ps);
	else if (ps->elements_a - 4 >= 0 && ps->stack_a[ps->elements_a - 4] < ps->med && \
ps->stack_a[ps->elements_a - 4] < ps->max && temp > 20 && argc > 120)
		multi_rra(ps);
	else if (ps->elements_a - 5 >= 0 && ps->stack_a[ps->elements_a - 5] < ps->med && \
ps->stack_a[ps->elements_a - 5] < ps->max && temp > 20 && argc > 120)
		multi_rra(ps);
	else
		ft_ra_glo(ps);
}

int	ft_quicksort_a_to_b_loop(t_struct *ps, int argc, int temp, int x)
{
	int	counter;

	counter = 0;
	while (ft_under_med(ps) && ps->elements_a > 2)
	{
		if (ps->elements_a - ps->ordered_ele < 5 && argc - 1 < 5)
			ft_check_switch_a(ps);
		if (temp == 0 && ps->stack_a[0] == ps->max && argc < 120)
			break ;
		if (ft_in_order(ps) == 1 && argc < 120)
			break ;
		else if (ps->stack_a[0] < ps->med && ps->stack_a[0] < ps->max)
		{
			ft_pb_glo(ps, argc);
			counter++;
			ps->counter2++;
			ps->chunk[x] = counter;
		}
		else
			ft_quicksort_a_to_b_sub(ps, temp, argc);
		if (temp == 0 && ps->elements_a > 2)
			temp = 8;
	}
	return (temp);
}

int	ft_quicksort_a_to_b(t_struct *ps, int temp, int argc, int x)
{
	ps->counter2 = 0;
	while (ps->elements_a > 2 && temp >= 1)
	{
		x++;
		temp = temp / 2;
		ft_selection_a(argc, ps, ps->counter2);
		if (ft_in_order(ps) == 0 && temp == 0 && argc < 120)
			temp = 10;
		temp = ft_quicksort_a_to_b_loop(ps, argc, temp, x);
	}
	if (ps->stack_a[ps->elements_a - 1] < ps->stack_a[0])
		ft_rra_glo(ps);
	if (ps->stack_a[ps->elements_a - 2] > ps->stack_a[ps->elements_a - 1])
		ft_rra_glo(ps);
	if (ps->stack_a[0] > ps->stack_a[1])
	{
		if (ps->stack_b[0] < ps->stack_b[1])
			ft_ss_glo(ps);
		else
			ft_sa_glo(ps);
	}
	x--;
	temp = x;
	return (temp);
}
