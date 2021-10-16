/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:40:39 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/22 15:47:59 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_over_med(t_struct *ps)
{
	int	i;

	i = 0;
	while (i < ps->ele_b)
	{
		if (ps->stack_b[i] > ps->med)
			return (1);
		i++;
	}
	return (0);
}

int	ft_under_med(t_struct *ps)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (i < ps->elements_a)
	{
		if (ps->stack_a[i] < ps->med \
		&& ps->stack_a[i] < ps->max)
			y = 1;
		i++;
	}
	return (y);
}

void	ft_check_switch_a(t_struct *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1])
	{
		if (ps->stack_b[0] < ps->stack_b[1])
			ft_ss_glo(ps);
		else
			ft_sa_glo(ps);
	}
	else if (ps->stack_a[0] > \
	ps->stack_a[ps->elements_a - 1])
	{
		ft_rra_glo(ps);
		if (ps->stack_b[0] < ps->stack_b[1])
			ft_ss_glo(ps);
		else
			ft_sa_glo(ps);
	}
}

void	ft_selection_loop(t_struct *ps, int i, int j)
{
	ps->min_select = 0;
	ps->temp = 0;
	while (i < ps->elements_a && i < ps->order)
	{
		j = i + 1;
		ps->min_select = ps->stack_temp_a[i];
		ps->temp = i;
		while (j < ps->elements_a && i < ps->order)
		{
			if (ps->stack_temp_a[j] < ps->min_select)
			{
				ps->min_select = ps->stack_temp_a[j];
				ps->temp = j;
			}
			j++;
		}
		ps->stack_temp_a[ps->temp] = ps->stack_temp_a[i];
		ps->stack_temp_a[i] = ps->min_select;
		i++;
	}
}

void	ft_selection(int argc, t_struct *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_stack_copy(argc, ps);
	ft_selection_loop(ps, i, j);
	ps->min = ps->stack_temp_a[0];
	ps->min_plus_one = ps->stack_temp_a[1];
	free(ps->stack_temp_a);
}
