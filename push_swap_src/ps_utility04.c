/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:19:22 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/23 12:14:09 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_order_sub_1(t_struct *ps, int i)
{
	ps->order = i + 1;
	ps->ordered_ele = ps->elements_a - ps->order;
	if (i != ps->elements_a - 1)
		ps->max = ps->stack_a[i + 1];
	return (1);
}

int	ft_order_sub_2(t_struct *ps, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ps->stack_a[i] > ps->stack_a[j])
			j++;
		else
			return (ft_order_sub_1(ps, i));
	}
	return (0);
}

int	ft_order(t_struct *ps)
{
	int	i;
	int	j;

	i = ps->elements_a - 1;
	j = 0;
	while (i < ps->elements_a && i > -1)
	{
		while (j < ps->ele_b)
		{
			if (ps->stack_b[j] > ps->stack_a[i])
				return (ft_order_sub_1(ps, i));
			j++;
		}
		if (i == 0 || ps->stack_a[i] > ps->stack_a[i - 1])
		{
			if (ft_order_sub_2(ps, i) == 1)
				return (1);
			i--;
		}
		else
			return (ft_order_sub_1(ps, i));
	}
	return (ft_order_sub_1(ps, i));
}
